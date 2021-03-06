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

wchar_t* wcsrchr (const wchar_t* wcs, wchar_t wc)
{
  /* Calling wcslen and then searching from the other end would cause more
     memory accesses. Avoid that, at the cost of a few more comparisons. */
  wchar_t* result = NULL;

  for (;; wcs++) {
    if (*wcs == wc)
      result = (wchar_t*) wcs;
    if (*wcs == (wchar_t)'\0')
      break;
  }
  return result;
}
