/* Copyright (C) 1993, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
   This file is part of the GNU IO Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2, or (at
   your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library; see the file COPYING.  If not, write to
   the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA.

   As a special exception, if you link this library with files
   compiled with a GNU compiler to produce an executable, this does
   not cause the resulting executable to be covered by the GNU General
   Public License.  This exception does not however invalidate any
   other reasons why the executable file might be covered by the GNU
   General Public License.  */

#include <stdio.h>
#include <libioP.h>
#include <errno.h>


off_t
ftello (fp)
     _IO_FILE *fp;
{
  _IO_pos_t pos;
  CHECK_FILE (fp, -1L);
  _IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile, fp);
  _IO_flockfile (fp);
  pos = _IO_seekoff (fp, 0, _IO_seek_cur, 0);
  if (_IO_in_backup (fp))
    pos -= fp->_IO_save_end - fp->_IO_save_base;
  _IO_funlockfile (fp);
  _IO_cleanup_region_end (0);
  if (pos == _IO_pos_BAD)
    {
#ifdef EIO
      if (errno == 0)
	__set_errno (EIO);
#endif
      return -1L;
    }
  return _IO_pos_as_off (pos);
}
