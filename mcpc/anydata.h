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

#ifndef h_pub_anydata
#define h_pub_anydata

#include <stdint.h>

#include "_c23_keywords.h"

enum mcpc_anytype
{
  MCPC_NONE = 0,
  MCPC_I8,
  MCPC_U8,
  MCPC_I16,
  MCPC_U16,
  MCPC_I32,
  MCPC_U32,
  MCPC_I64,
  MCPC_U64,
  MCPC_U8STR,
  MCPC_I8S,
  MCPC_U8S,
  MCPC_I16S,
  MCPC_U16S,
  MCPC_I32S,
  MCPC_U32S,
  MCPC_I64S,
  MCPC_U64S,
  MCPC_FUNC,
};
typedef enum mcpc_anytype mcpc_anytype_t;

typedef struct mcpc_anydata mcpc_anydata_t;

typedef struct mcpc_anypool mcpc_anypool_t;


#ifdef MCPC_C23GIVUP_FIXENUM
enum mcpc_mime
#else
enum mcpc_mime:uint16_t
#endif
{
  MCPC_MIME_NONE = 0,
  MCPC_MIME_TEXT_PLAIN,
  MCPC_MIME_IMAGE_PNG,
  MCPC_MIME_IMAGE_JPEG,
  MCPC_MIME_IMAGE_GIF,
  MCPC_MIME_AUDIO_MPEG,
  MCPC_MIME_AUDIO_WAV,
  MCPC_MIME_VIDEO_MPEG,
  MCPC_MIME_VIDEO_AVI,
  MCPC_MIME_APPLI_OCTS,
  MCPC_MIME_APPLI_JSON,
  MCPC_MIME_APPLI_PDF,
};
typedef enum mcpc_mime mcpc_mime_t;


static inline bool
mcpc_anytype_is_intlike (mcpc_anytype_t typ)
{
  if (typ == MCPC_I8 || typ == MCPC_I16 || typ == MCPC_I32 || typ == MCPC_I64 || typ == MCPC_U8 || typ == MCPC_U16
      || typ == MCPC_U32 || typ == MCPC_U64 || typ == MCPC_FUNC)
    return true;

  return false;
}

static inline bool
mcpc_anytype_is_arrlike (mcpc_anytype_t typ)
{
  if (typ == MCPC_U8STR || typ == MCPC_I8S || typ == MCPC_I16S || typ == MCPC_I32S || typ == MCPC_I64S
      || typ == MCPC_U8S || typ == MCPC_U16S || typ == MCPC_U32S || typ == MCPC_U64S)
    return true;

  return false;
}


#endif
