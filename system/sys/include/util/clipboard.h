/*  libatheos.so - the highlevel API library for AtheOS
 *  Copyright (C) 1999 - 2001 Kurt Skauen
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

#ifndef __F_GUI_CLIPBOARD_H__
#define __F_GUI_CLIPBOARD_H__

#include <util/message.h>
#include <util/locker.h>

#include <string>

namespace os
{
#if 0
}
#endif

/** 
 * \ingroup util
 * \par Description:
 *
 * \sa
 * \author	Kurt Skauen (kurt@atheos.cx)
 *****************************************************************************/

class Clipboard
{
public:
    Clipboard();
    Clipboard( const char* pzName );
    ~Clipboard();

    bool	Lock();
    void	Unlock();

    void	Clear();
    void	Commit();
  
    Message* GetData();
//  status_t SetData( Message* pcBuffer );
  
private:
    Locker	m_cMutex;
    std::string	m_cName;
    port_id	m_hServerPort;
    port_id	m_hReplyPort;
    Message	m_cBuffer;
    bool		m_bCleared;
};



}
#endif // __F_GUI_CLIPBOARD_H__
