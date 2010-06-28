
/*
 *  The AtheOS application server
 *  Copyright (C) 1999  Kurt Skauen
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of version 2 of the GNU Library
 *  General Public License as published by the Free Software
 *  Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "clipboard.h"

#include <atheos/kdebug.h>

#include <util/message.h>

using namespace os;

SrvClipboard::ClipboardMap SrvClipboard::s_cClipboardMap;


void SrvClipboard::SetData( const char *pzName, uint8 *pData, int nOffset, int nFragmentSize, int nTotalSize )
{
	if( nOffset + nFragmentSize > nTotalSize || nOffset < 0 || nFragmentSize < 0 || nTotalSize < 0 )
	{
		dbprintf( "Error: invalid parameters in clipboard SetData request!\n" );
		return;
	}
	
	SrvClipboard *pcClipboard;
	ClipboardMap::iterator i = s_cClipboardMap.find( pzName );

	if( i == s_cClipboardMap.end() )
	{
		pcClipboard = new SrvClipboard();
		s_cClipboardMap[pzName] = pcClipboard;
	}
	else
	{
		pcClipboard = ( *i ).second;
	}

	if( pcClipboard->m_nSize != nTotalSize || pcClipboard->m_pData == NULL )
	{
		delete[]pcClipboard->m_pData;
		pcClipboard->m_pData = new uint8[nTotalSize];

		pcClipboard->m_nSize = nTotalSize;
	}

	memcpy( pcClipboard->m_pData + nOffset, pData, nFragmentSize );
}

uint8 *SrvClipboard::GetData( const char *pzName, int *pnSize )
{
	ClipboardMap::iterator i = s_cClipboardMap.find( pzName );

	if( i == s_cClipboardMap.end() )
	{
		return ( NULL );
	}
	*pnSize = ( *i ).second->m_nSize;
	return ( ( *i ).second->m_pData );
}
