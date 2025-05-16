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

#ifndef h_complt
#define h_complt

// not supposed to be used by lib users

#include <mcpc/_c23_keywords.h>
#include <mcpc/_c23_uchar.h>

#include "ext_string.h"

#include <mcpc/anydata.h>

#include "errcode.h"

#include "prmpt.h"
#include "rsc.h"


typedef mcpc_anydata_t mcpc_complt_t;
typedef mcpc_anydata_t mcpc_compltcand_t;

mcpc_complt_t *mcpc_complt_new_prmptarg (const mcpc_prmpt_t * prmpt, const char8_t * argname, size_t argname_len,
					 const char8_t * argval, size_t argval_len);

mcpc_complt_t *mcpc_complt_new_rsc (const mcpc_rscpool_t * rscpool, const char8_t * uri, size_t uri_len);

void mcpc_complt_free (mcpc_complt_t * complt);

const mcpc_compltcand_t *mcpc_complt_get_next_compltcand (const mcpc_complt_t * complt);

mcpc_errcode_t mcpc_complt_get_compltcandi_len (const mcpc_complt_t * complt, size_t *ret);


mcpc_errcode_t
mcpc_compltcand_getref_u8str (const mcpc_compltcand_t * compltcand, const char8_t ** ret, size_t *ret_len);



#endif
