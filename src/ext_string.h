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

#ifndef h__string
#define h__string

#include <string.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#include <mcpc/_c23_keywords.h>
#include <mcpc/_c23_uchar.h>

#define u8c1(a) u8##"" a
#define u8c2(a, b) u8##"" a b
#define u8c3(a, b, c) u8##"" a b c
#define u8c4(a, b, c, d) u8##"" a b c d
#define u8c5(a, b, c, d, e) u8##"" a b c d e
#define u8c6(a, b, c, d, e, f) u8##"" a b c d e f
#define u8c7(a, b, c, d, e, f, g) u8##"" a b c d e f g

inline static bool
u8streq(const char8_t* a, const char8_t* b)
{
  const char* const aa = (const char* const)a;
  const char* const bb = (const char* const)b;
  return strcmp(aa, bb) == 0;
}

inline static size_t
u8strlen(const char8_t* u8s)
{
  const char* s = (const char*)u8s;
  return strlen(s);
}

static inline int
u8strcmp (const char8_t *s1, const char8_t *s2)
{
  return strcmp ((const char *) s1, (const char *) s2);
}

static inline int
u8strncmp (const char8_t *s1, const char8_t *s2, size_t n)
{
  return strncmp ((const char *) s1, (const char *) s2, n);
}

static inline bool
beg_with_alph(const char8_t* const u8s)
{
  const char* const s = (const char* const)u8s;
  return s[0] == '/' || isalpha((int)s[0]);
}

#endif
