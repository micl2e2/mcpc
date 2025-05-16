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

#ifndef h_pub_server
#define h_pub_server

#include <stdio.h>

#include "visb.h"
#include "_c23_keywords.h"

#include "errcode.h"
#include "tool.h"
#include "prmpt.h"
#include "rsc.h"


typedef struct mcpc_server mcpc_server_t;

MCPC_API mcpc_server_t *
mcpc_server_new_iostrm (const FILE *const strm_in, const FILE *const strm_out);

MCPC_API mcpc_server_t *
mcpc_server_new_tcp ();

MCPC_API mcpc_errcode_t
mcpc_server_set_name (mcpc_server_t *sv, const char8_t *name, size_t name_len);

MCPC_API mcpc_errcode_t
mcpc_server_set_nament (mcpc_server_t *sv, const char8_t *nament);

MCPC_API mcpc_errcode_t
mcpc_server_capa_enable_prmt (mcpc_server_t *sv);

MCPC_API mcpc_errcode_t
mcpc_server_capa_enable_prmt_listchg (mcpc_server_t *sv);

MCPC_API mcpc_errcode_t
mcpc_server_capa_enable_tool (mcpc_server_t *sv);

MCPC_API mcpc_errcode_t
mcpc_server_capa_enable_tool_listchg (mcpc_server_t *sv);

MCPC_API mcpc_errcode_t
mcpc_server_capa_enable_rsc (mcpc_server_t *sv);

MCPC_API mcpc_errcode_t
mcpc_server_capa_enable_rsc_subscr (mcpc_server_t *sv);

MCPC_API mcpc_errcode_t
mcpc_server_capa_enable_rsc_listchg (mcpc_server_t *sv);

MCPC_API mcpc_errcode_t
mcpc_server_capa_enable_complt (mcpc_server_t *sv);

MCPC_API mcpc_errcode_t
mcpc_server_add_tool (mcpc_server_t *sv, mcpc_tool_t *tool);

MCPC_API mcpc_errcode_t
mcpc_server_add_prmpt (mcpc_server_t *sv, mcpc_prmpt_t *prmpt);

MCPC_API mcpc_errcode_t
mcpc_server_add_rsc (mcpc_server_t *sv, mcpc_rsc_t *rsc);

MCPC_API mcpc_errcode_t
mcpc_server_start (mcpc_server_t *sv);

MCPC_API mcpc_errcode_t
mcpc_server_close (mcpc_server_t *sv);

#endif
