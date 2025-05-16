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

#ifndef h_ucbr
#define h_ucbr

#include <stddef.h>

#include <mcpc/ucbr.h>

typedef mcpc_anydata_t mcpc_ucbrchd_t;

bool mcpc_ucbrchd_is_tool_callres (const mcpc_ucbrchd_t * ucbrchd);

bool mcpc_ucbrchd_is_prmpt_callres (const mcpc_ucbrchd_t * ucbrchd);

bool mcpc_ucbrchd_is_assist_prmpt (const mcpc_ucbrchd_t * ucbrchd);

mcpc_errcode_t mcpc_ucbrchd_getref_u8str (const mcpc_ucbrchd_t * ucbrchd, const char8_t ** ret, size_t *ret_len);

mcpc_errcode_t mcpc_ucbrchd_get_data_type (const mcpc_ucbrchd_t * ucbrchd, mcpc_anytype_t * ret);

// ------------------------------ ucbr ------------------------------

mcpc_ucbr_t *mcpc_ucbr_new ();

void mcpc_ucbr_free (mcpc_ucbr_t * ucbr);

const mcpc_ucbrchd_t *mcpc_ucbr_get_next (const mcpc_ucbr_t * ucbr);

size_t mcpc_ucbr_get_serlz_lenhint (const mcpc_ucbr_t * ucbr);

void mcpc_ucbr_addfre (mcpc_ucbr_t * ucbr, mcpc_ucbrchd_t * ucbrchd);

bool mcpc_ucbr_is_err (const mcpc_ucbr_t * ucbr);



#endif
