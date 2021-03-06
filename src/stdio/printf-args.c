/* Copyright (C) 1999, 2005 Free Software Foundation, Inc.
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

#include <stdio.h>
#include <stdarg.h>
#include "printf-args.h"

int utf8_printf_fetchargs (va_list args, arguments* a)
{
  unsigned int i;
  argument* ap;
  for (i = 0, ap = &a->arg[0]; i < a->count; i++, ap++)
    switch (ap->type) {
      case TYPE_SCHAR:
        ap->a.a_schar = va_arg(args, /*signed char*/ int);
        break;
      case TYPE_UCHAR:
        ap->a.a_uchar = va_arg(args, /*unsigned char*/ int);
        break;
      case TYPE_SHORT:
        ap->a.a_short = va_arg(args, /*short*/ int);
        break;
      case TYPE_USHORT:
        ap->a.a_ushort = va_arg(args, /*unsigned short*/ int);
        break;
      case TYPE_INT:
        ap->a.a_int = va_arg(args, int);
        break;
      case TYPE_UINT:
        ap->a.a_uint = va_arg(args, unsigned int);
        break;
      case TYPE_LONGINT:
        ap->a.a_longint = va_arg(args, long int);
        break;
      case TYPE_ULONGINT:
        ap->a.a_ulongint = va_arg(args, unsigned long int);
        break;
#ifdef HAVE_LONG_LONG
      case TYPE_LONGLONGINT:
        ap->a.a_longlongint = va_arg(args, long long int);
        break;
      case TYPE_ULONGLONGINT:
        ap->a.a_ulonglongint = va_arg(args, unsigned long long int);
        break;
#endif
      case TYPE_DOUBLE:
        ap->a.a_double = va_arg(args, double);
        break;
#ifdef HAVE_LONG_DOUBLE
      case TYPE_LONGDOUBLE:
        ap->a.a_longdouble = va_arg(args, long double);
        break;
#endif
      case TYPE_CHAR:
        ap->a.a_char = va_arg(args, int);
        break;
      case TYPE_WIDE_CHAR:
        /* Although ISO C 99 7.24.1.(2) says that wint_t is "unchanged by
           default argument promotions", this is not the case in mingw32,
           where wint_t is 'unsigned short'.  */
        ap->a.a_wide_char =
          (sizeof (wint_t) < sizeof (int)
           ? va_arg (args, int)
           : va_arg (args, wint_t));
        break;
      case TYPE_STRING:
        ap->a.a_string = va_arg(args, const char*);
        break;
      case TYPE_WIDE_STRING:
        ap->a.a_wide_string = va_arg(args, const wchar_t*);
        break;
      case TYPE_POINTER:
        ap->a.a_pointer = va_arg(args, void*);
        break;
      case TYPE_COUNT_SCHAR_POINTER:
        ap->a.a_count_schar_pointer = va_arg(args, signed char *);
        break;
      case TYPE_COUNT_SHORT_POINTER:
        ap->a.a_count_short_pointer = va_arg(args, short *);
        break;
      case TYPE_COUNT_INT_POINTER:
        ap->a.a_count_int_pointer = va_arg(args, int *);
        break;
      case TYPE_COUNT_LONGINT_POINTER:
        ap->a.a_count_longint_pointer = va_arg(args, long int *);
        break;
#ifdef HAVE_LONG_LONG
      case TYPE_COUNT_LONGLONGINT_POINTER:
        ap->a.a_count_longlongint_pointer = va_arg(args, long long int *);
        break;
#endif
      default:
        fprintf(stderr, "utf8_printf: Unknown type for argument %u\n", i);
        return -1;
    }
  return 0;
}
