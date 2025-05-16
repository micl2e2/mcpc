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

#ifndef h_pub_ucbr
#define h_pub_ucbr

#include <stdarg.h>

#include "_c23_uchar.h"
#include "visb.h"

#include "anydata.h"
#include "errcode.h"

typedef mcpc_anypool_t mcpc_ucbr_t;

MCPC_API void
mcpc_ucbr_toolcall_add_text_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt, ...);

MCPC_API void
mcpc_ucbr_toolcall_add_errmsg_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt, ...);

MCPC_API void
mcpc_ucbr_prmptget_add_user_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt, ...);

MCPC_API void
mcpc_ucbr_prmptget_add_assist_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt, ...);

#define mcpc_toolcall_result_add_text_printf8 mcpc_ucbr_toolcall_add_text_printf8

#define mcpc_toolcall_result_add_errmsg_printf8 mcpc_ucbr_toolcall_add_errmsg_printf8

#define mcpc_prmptget_result_add_user_printf8 mcpc_ucbr_prmptget_add_user_printf8

#define mcpc_prmptget_result_add_assist_printf8 mcpc_ucbr_prmptget_add_assist_printf8

#endif
