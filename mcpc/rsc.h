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

#ifndef h_pub_rsc
#define h_pub_rsc

#include "_c23_uchar.h"
#include "visb.h"

#include "anydata.h"
#include "errcode.h"

typedef mcpc_anydata_t mcpc_rsc_t;

MCPC_API mcpc_rsc_t *
mcpc_rsc_new (const char8_t *uri, const size_t uri_len, const char8_t *name, const size_t name_len);

MCPC_API mcpc_rsc_t *
mcpc_rsc_new2 (const char8_t *uri_nt, const char8_t *nament);

MCPC_API mcpc_rsc_t *
mcpc_rsc_new3 (mcpc_mime_t mime, const char8_t *uri_nt, const char8_t *nament);

MCPC_API void
mcpc_rsc_free (mcpc_rsc_t *rsc);

MCPC_API mcpc_errcode_t
mcpc_rsc_get_uri (const mcpc_rsc_t *rsc, char8_t *ret, size_t ret_cap, size_t *ret_len);

MCPC_API mcpc_errcode_t
mcpc_rsc_getref_uri (const mcpc_rsc_t *rsc, const char8_t **ret, size_t *ret_len);

MCPC_API mcpc_errcode_t
mcpc_rsc_getref_name (const mcpc_rsc_t *rsc, const char8_t **ret, size_t *ret_len);

MCPC_API mcpc_errcode_t
mcpc_rsc_get_mime (const mcpc_rsc_t *rsc, mcpc_mime_t *ret);

MCPC_API void
mcpc_rsc_set_mime (mcpc_rsc_t *rsc, mcpc_mime_t mime);

#endif
