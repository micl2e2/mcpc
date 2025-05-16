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

#ifndef h_prmpt
#define h_prmpt

#include <mcpc/prmpt.h>

typedef mcpc_anypool_t mcpc_prmptpool_t;
typedef mcpc_anypool_t mcpc_prmptargpool_t;

// ---------------------------- prmptarg ----------------------------

void mcpc_prmptarg_free (mcpc_prmptarg_t * prmptarg);

bool mcpc_prmptarg_is_required (const mcpc_prmptarg_t * prmptarg);

mcpc_errcode_t mcpc_prmptarg_getref_name (const mcpc_prmptarg_t * prmptarg, const char8_t ** ret, size_t *ret_len);

mcpc_errcode_t mcpc_prmptarg_getref_desc (const mcpc_prmptarg_t * prmptarg, const char8_t ** ret, size_t *ret_len);

mcpc_errcode_t mcpc_prmptarg_get_data_type (const mcpc_prmptarg_t * prmptarg, mcpc_anytype_t * ret);

mcpc_errcode_t mcpc_prmptarg_set_required (mcpc_prmptarg_t * prmptarg, bool fl);

mcpc_errcode_t mcpc_prmptarg_set_nament (mcpc_prmptarg_t * prmptarg, const char8_t * name);

mcpc_errcode_t mcpc_prmptarg_set_u8str (mcpc_prmptarg_t * prmptarg, const char8_t * arr, size_t arr_len);

// ------------------------------ prmpt ------------------------------

mcpc_errcode_t mcpc_prmpt_getref_name (const mcpc_prmpt_t * prmpt, const char8_t ** ret, size_t *ret_len);

mcpc_errcode_t mcpc_prmpt_getref_desc (const mcpc_prmpt_t * prmpt, const char8_t ** ret, size_t *ret_len);

void mcpc_prmpt_free (mcpc_prmpt_t * prmpt);

// ---------------------------- prmptpool ----------------------------

mcpc_prmptpool_t *mcpc_prmptpool_new ();

void mcpc_prmptpool_free (mcpc_prmptpool_t * prmptpool);

void mcpc_prmptpool_addcpy (mcpc_prmptpool_t * prmptpool, const mcpc_prmpt_t * prmpt);

void mcpc_prmptpool_addfre (mcpc_prmptpool_t * prmptpool, mcpc_prmpt_t * prmpt);

size_t mcpc_prmptpool_get_len (const mcpc_prmptpool_t * prmptpool);

const mcpc_prmpt_t *mcpc_prmptpool_get (const mcpc_prmptpool_t * prmptpool, size_t idx);

const mcpc_prmpt_t *mcpc_prmptpool_getbyname (const mcpc_prmptpool_t * prmptpool, const char8_t * name,
					      size_t name_len);

// -------------------------- prmptarghint --------------------------

const mcpc_prmptarghint_t *mcpc_prmptarg_get_next_prmptarghint (const mcpc_prmptarg_t * prmptarg);

mcpc_errcode_t
mcpc_prmptarghint_getref_u8str (const mcpc_prmptarg_t * prmptarghint, const char8_t ** ret, size_t *ret_len);

#endif
