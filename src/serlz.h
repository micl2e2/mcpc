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

#ifndef h_serialize
#define h_serialize

#include "retbuf.h"
#include "tool.h"
#include "rsc.h"
#include "server.h"
#include "ucbr.h"
#include "complt.h"

#define L_QUO u8c1("\"")
#define R_QUO u8c1("\"")
#define L_QUO_D u8c1("(")
#define R_QUO_D u8c1(")")

u8_t serlz_tool (retbuf_t rtbf, const mcpc_tool_t * tool);

u8_t serlz_toolpool (retbuf_t rtbf, const mcpc_toolpool_t * pool);

u8_t serlz_prmptpool (retbuf_t rtbf, const mcpc_prmptpool_t * prmptpool);

u8_t serlz_initres (retbuf_t rtbf, const mcpc_server_t * sv);

u8_t serlz_rsc (retbuf_t rtbf, const mcpc_rsc_t * rsc);

u8_t serlz_rscpool (retbuf_t rtbf, const mcpc_rscpool_t * rscpool);

// deprecated
u8_t serlz_ucbrchd (retbuf_t rtbf, const mcpc_ucbrchd_t * ucbrchd);

// deprecated
u8_t serlz_ucbr (retbuf_t rtbf, const mcpc_ucbr_t * ucbr);

u8_t serlz_tool_callres (retbuf_t rtbf, const mcpc_ucbr_t * ucbr);

u8_t serlz_prmpt_callres (retbuf_t rtbf, const mcpc_ucbr_t * ucbr);

u8_t serlz_complt (retbuf_t rtbf, const mcpc_complt_t * complt);


#endif
