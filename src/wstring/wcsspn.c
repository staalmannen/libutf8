/* Copyright (C) 1999 Free Software Foundation, Inc.
   This file is part of the GNU UTF-8 Library.

   The GNU UTF-8 Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU UTF-8 Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU UTF-8 Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#include <utf8/wchar.h>

size_t wcsspn (const wchar_t* wcs, const wchar_t* accept)
{
  /* Optimize two cases. */
  if (accept[0] == (wchar_t)'\0')
    return 0;
  if (accept[1] == (wchar_t)'\0') {
    wchar_t wc = accept[0];
    const wchar_t* ptr = wcs;
    for (; *ptr != (wchar_t)'\0'; ptr++) {
      if (*ptr != wc)
        break;
    }
    return ptr-wcs;
  }
  /* General case. */
  {
    const wchar_t* ptr = wcs;
    for (; *ptr != (wchar_t)'\0'; ptr++) {
      if (!wcschr(accept, *ptr))
        break;
    }
    return ptr-wcs;
  }
}
