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

#ifndef h_pub_tool
#define h_pub_tool

#include <stddef.h>
#include <stdint.h>

#include "_c23_uchar.h"
#include "visb.h"

#include "anydata.h"
#include "errcode.h"
#include "ucbr.h"

typedef mcpc_anydata_t mcpc_toolprop_t;

typedef mcpc_anydata_t mcpc_tool_t;

typedef void (*mcpc_tcallcb_t) (const mcpc_tool_t *tool, mcpc_ucbr_t *ucbr);

MCPC_API mcpc_toolprop_t *
mcpc_toolprop_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len, mcpc_anytype_t typ);

MCPC_API mcpc_toolprop_t *
mcpc_toolprop_new2 (const char8_t *nament, const char8_t *descnt, mcpc_anytype_t typ);

MCPC_API mcpc_tool_t *
mcpc_tool_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len);

MCPC_API mcpc_tool_t *
mcpc_tool_new2 (const char8_t *nament, const char8_t *descnt);

MCPC_API void
mcpc_tool_addfre_toolprop (mcpc_tool_t *tool, mcpc_toolprop_t *toolprop);

MCPC_API void
mcpc_tool_addcpy_toolprop (mcpc_tool_t *tool, mcpc_toolprop_t *toolprop);

#define mcpc_tool_add_toolprop mcpc_tool_addfre_toolprop

MCPC_API const mcpc_toolprop_t *
mcpc_tool_get_toolprop (const mcpc_tool_t *tool, size_t idx);

MCPC_API size_t
mcpc_tool_get_toolprop_len (const mcpc_tool_t *tool);

MCPC_API const mcpc_toolprop_t *
mcpc_tool_get_next_toolprop (const mcpc_tool_t *tool);

MCPC_API mcpc_errcode_t
mcpc_tool_get_tpropval_i32 (const mcpc_tool_t *tool, const char8_t *tprop_nament, int32_t *ret);

MCPC_API mcpc_errcode_t
mcpc_tool_get_tpropval_u8str (const mcpc_tool_t *tool, const char8_t *tprop_nament, char8_t *ret, size_t ret_cap, size_t *ret_len);

MCPC_API mcpc_errcode_t
mcpc_tool_get_call_cb (const mcpc_tool_t *tool, mcpc_tcallcb_t *ret);

MCPC_API mcpc_errcode_t
mcpc_tool_set_call_cb (mcpc_tool_t *tool, mcpc_tcallcb_t cb);

#endif
