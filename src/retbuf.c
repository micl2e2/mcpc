// This file is part of the mcpc library.
//
// Copyright (C) 2025 Michael Lee <micl2e2 AT proton.me>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions: 
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software. 
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "retbuf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mjson.h"

retbuf_t
retbuf_new (size_t cap, size_t *len)
{
  retbuf_t x = {
    .cap = cap,.buf0 = malloc (cap),.len = len
  };
  return x;
}

void
retbuf_free (retbuf_t rtbf)
{
  free (rtbf.buf0);
}

uint8_t
rtbuf_printf_adv (retbuf_t rtbf, size_t advl, const char8_t *u8str, ...)
{
  va_list args;
  va_start (args, u8str);
  const char *str = (const char *) u8str;
  vsprintf (rtbf.buf0 + *rtbf.len, str, args);
  if (*rtbf.len + advl > rtbf.cap)
    {
      exit (122);
    }
  *rtbf.len += advl;
  va_end (args);
  return 0;
}

uint8_t
rtbuf_printf (retbuf_t rtbf, const char8_t *u8str, ...)
{
  va_list args;
  va_start (args, u8str);

  const char *str = (const char *) u8str;
  size_t strl = strlen (str);
  rtbuf_printf_adv (rtbf, strl, u8str, args);

  va_end (args);
  return 0;
}

uint8_t
rtbuf_printf_mjfmt (retbuf_t rtbf, const char8_t *fmt8, ...)
{
  va_list args;
  va_start (args, fmt8);

  const char *fmt = (const char *) fmt8;
  struct mjson_fixedbuf fb = { rtbf.buf0, (int)rtbf.cap, (int)*rtbf.len };
  int advl = mjson_vprintf (&mjson_print_fixed_buf, &fb, fmt, &args);

  *rtbf.len += advl;

  va_end (args);
  return 0;
}

// TODO change _printf_ use this one
u8_t
rtbuf_vprintf_mjfmt (retbuf_t rtbf, const char8_t *fmt8, va_list *vargs)
{
  const char *fmt = (const char *) fmt8;
  struct mjson_fixedbuf fb = { rtbf.buf0, (int)rtbf.cap, (int)*rtbf.len };
  int advl = mjson_vprintf (&mjson_print_fixed_buf, &fb, fmt, vargs);	// TODO: __va_list_tag (*)[1]’
  *rtbf.len += advl;
  return 0;
}
