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

#include "sysdep-alloca.h"

#include <utf8/wchar.h>

#include <utf8/wctype.h>
#include "config.h"
#include "integer-parse.h"

#ifdef HAVE_LONG_LONG

#ifdef HAVE_STRTOULL
extern unsigned long long int strtoull();
#endif

unsigned long long int wcstoull (const wchar_t* nptr, wchar_t** endptr, int base)
{
  const wchar_t* eptr;
  size_t n;
  char* tmp;
  unsigned long long int result;

  /* Skip whitespace. */
  for (; *nptr != (wchar_t)'\0' && iswspace(*nptr); nptr++);

  /* Parse number. */
  eptr = utf8_integer_parse(nptr,base);

  /* Fill it into a char* string. */
  n = eptr - nptr;
  tmp = alloca(n+1);
  {
    const wchar_t* p1;
    char* p2 = tmp;
    for (p1 = nptr; p1 < eptr; p1++)
      *p2++ = wctob(*p1);
    *p2 = '\0';
  }

  /* Convert to number. */
#ifdef HAVE_STRTOULL
  result = strtoull(tmp,NULL,base);
#else
  result = strtoul(tmp,NULL,base);
#endif

  freea(tmp);
  if (endptr)
    *endptr = (wchar_t*) eptr;
  return result;
}

#endif
