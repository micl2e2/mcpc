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

#ifndef h_pub_prmpt
#define h_pub_prmpt

#include <stddef.h>

#include "_c23_uchar.h"
#include "visb.h"

#include "anydata.h"
#include "errcode.h"
#include "ucbr.h"

typedef mcpc_anydata_t mcpc_prmptarghint_t;

typedef mcpc_anydata_t mcpc_prmptarg_t;

typedef mcpc_anydata_t mcpc_prmpt_t;

typedef void (*mcpc_prmpt_callcb_t) (const mcpc_prmpt_t *prmpt, mcpc_ucbr_t *ucbr);

MCPC_API mcpc_prmptarg_t *
mcpc_prmptarg_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len);

MCPC_API mcpc_prmptarg_t *
mcpc_prmptarg_new2 (const char8_t *nament, const char8_t *descnt);

MCPC_API mcpc_prmptarg_t *
mcpc_prmptarg_new3 (const char8_t *nament);

MCPC_API mcpc_errcode_t
mcpc_prmptarg_get_u8str (const mcpc_prmptarg_t *prmptarg, char8_t *ret, size_t ret_cap, size_t *ret_len);

MCPC_API mcpc_errcode_t
mcpc_prmptarg_getref_u8str (const mcpc_prmptarg_t *prmptarg, const char8_t **ret, size_t *ret_len);

MCPC_API mcpc_errcode_t
mcpc_prmptarg_add_hint_printf8 (mcpc_prmptarg_t *prmptarg, const char8_t *fmt, ...);

MCPC_API mcpc_prmpt_t *
mcpc_prmpt_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len);

MCPC_API mcpc_prmpt_t *
mcpc_prmpt_new2 (const char8_t *nament, const char8_t *descnt);

MCPC_API mcpc_prmpt_t *
mcpc_prmpt_new3 (const char8_t *nament);

MCPC_API mcpc_errcode_t
mcpc_prmpt_addfre_prmptarg (mcpc_prmpt_t *prmpt, mcpc_prmptarg_t *prmptarg);

MCPC_API void
mcpc_prmpt_addcpy_prmptarg (mcpc_prmpt_t *prmpt, mcpc_prmptarg_t *prmptarg);

#define mcpc_prmpt_add_prmptarg mcpc_prmpt_addfre_prmptarg

MCPC_API const mcpc_prmptarg_t *
mcpc_prmpt_get_prmptarg (const mcpc_prmpt_t *prmpt, size_t idx);

MCPC_API size_t
mcpc_prmpt_get_prmptarg_len (const mcpc_prmpt_t *prmpt);

MCPC_API const mcpc_prmptarg_t *
mcpc_prmpt_get_next_prmptarg (const mcpc_prmpt_t *prmpt);

MCPC_API const mcpc_prmptarg_t *
mcpc_prmpt_getbyname_prmptarg (const mcpc_prmpt_t *prmpt, const char8_t *parg_name, size_t parg_name_len);

MCPC_API const mcpc_prmptarg_t *
mcpc_prmpt_getbynament_prmptarg (const mcpc_prmpt_t *prmpt, const char8_t *parg_nament);

MCPC_API mcpc_errcode_t
mcpc_prmpt_get_callcb (const mcpc_prmpt_t *prmpt, mcpc_prmpt_callcb_t *ret);

MCPC_API mcpc_errcode_t
mcpc_prmpt_set_callcb (mcpc_prmpt_t *prmpt, mcpc_prmpt_callcb_t cb);

#endif
