/*  libsyllable.so - the highlevel API library for Syllable
 *  Copyright (C) 2004 Syllable Team
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of version 2 of the GNU Library
 *  General Public License as published by the Free Software
 *  Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 *  MA 02111-1307, USA
 */

#include <util/locale.h>
#include <util/resources.h>
#include <storage/file.h>
#include <locale.h>

using namespace os;

class Locale::Private
{
	public:

	Private() {
	}

	~Private() {
		if( m_pcCol ) {
			delete m_pcCol;
		}
	}
	
	Resources* GetResources() {
		if( !m_pcCol ) {
			m_pcCol = new Resources( get_image_id() );
		}
		return m_pcCol;
	}

	String		m_cName;
	Resources*	m_pcCol;
};

Locale::Locale( )
{
	m = new Private;
	
	char *lang = getenv( "LANG" );
	
	if( lang ) {
		char *p = lang;
		char bfr[128], *q;
		uint i;
		for( i = 0, q = bfr; *p && *p != '_' && i < sizeof(bfr); p++, i++, q++ ) {
			*q = *p;
		}
		*q = '\0';
		SetName( bfr );
	} else {
		SetName( "C" );
	}
}

Locale::Locale( int nCategory )
{
	m = new Private;
	
	SetName( setlocale( nCategory, NULL ) );
}

Locale::Locale( const Locale& cLocale )
{
	m = new Private;
	SetName( cLocale.GetName() );
}

Locale::~Locale()
{
	delete m;
}

const String& Locale::GetName() const
{
	return m->m_cName;
}

void Locale::SetName( const String& cName )
{
	m->m_cName = cName;
}

StreamableIO* Locale::GetResourceStream( const String& cName )
{
	Resources* pcCol = NULL;
	StreamableIO* pcStream = NULL;

	try {
		pcCol = m->GetResources();
	} catch( ... ) {
		// eat "could not find resource section" exceptions
	}

	if( pcCol ) {
		pcStream = pcCol->GetResourceStream( cName );
	}

	if( !pcStream ) {
		try {
			pcStream = new File( String("resources/") + cName );
		} catch( ... ) {
			if( pcStream ) delete pcStream;
			pcStream = NULL;
		}
	}

	return pcStream;
}

StreamableIO* Locale::GetLocalizedResourceStream( const String& cName )
{
	StreamableIO* pcStream;

	pcStream = GetResourceStream( m->m_cName + String("/") + cName );
	
	if( pcStream == NULL ) {
		pcStream = GetResourceStream( cName );
	}

	return pcStream;
}
