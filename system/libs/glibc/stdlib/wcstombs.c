/* Copyright (C) 1991,1992,1995,1996,1997,1999 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#include <stdlib.h>
#include <string.h>
#include <wchar.h>


/* Convert the `wchar_t' string in PWCS to a multibyte character string
   in S, writing no more than N characters.  Return the number of bytes
   written, or (size_t) -1 if an invalid `wchar_t' was found.  */
size_t
wcstombs (char *s, const wchar_t *pwcs, size_t n)
{
  mbstate_t state;

  memset (&state, '\0', sizeof state);

  /* Return how many we wrote (or maybe an error).  */
  return __wcsrtombs (s, &pwcs, n, &state);
}
