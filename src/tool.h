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

#ifndef h_tool
#define h_tool

#include <mcpc/tool.h>

#include "ext_stdint.h"

typedef mcpc_anypool_t mcpc_toolpool_t;
typedef mcpc_anypool_t mcpc_toolproppool_t;

// ---------------------------- toolprop ----------------------------

void mcpc_toolprop_free (mcpc_toolprop_t * toolprop);

mcpc_errcode_t mcpc_toolprop_getref_name (const mcpc_toolprop_t * toolprop, const char8_t ** ret, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_getref_desc (const mcpc_toolprop_t * toolprop, const char8_t ** ret, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_get_data_type (const mcpc_toolprop_t * toolprop, mcpc_anytype_t * ret);

mcpc_errcode_t mcpc_toolprop_set_nament (mcpc_toolprop_t * toolprop, const char8_t * name);

mcpc_errcode_t mcpc_toolprop_set_i8 (mcpc_toolprop_t * toolprop, i8_t val);

mcpc_errcode_t mcpc_toolprop_set_u8 (mcpc_toolprop_t * toolprop, u8_t val);

mcpc_errcode_t mcpc_toolprop_set_i16 (mcpc_toolprop_t * toolprop, i16_t val);

mcpc_errcode_t mcpc_toolprop_set_u16 (mcpc_toolprop_t * toolprop, u16_t val);

mcpc_errcode_t mcpc_toolprop_set_i32 (mcpc_toolprop_t * toolprop, i32_t val);

mcpc_errcode_t mcpc_toolprop_set_u32 (mcpc_toolprop_t * toolprop, u32_t val);

mcpc_errcode_t mcpc_toolprop_set_i64 (mcpc_toolprop_t * toolprop, i64_t val);

mcpc_errcode_t mcpc_toolprop_set_u64 (mcpc_toolprop_t * toolprop, u64_t val);

mcpc_errcode_t mcpc_toolprop_set_func (mcpc_toolprop_t * toolprop, void *val);

mcpc_errcode_t mcpc_toolprop_get_i8 (const mcpc_toolprop_t * toolprop, i8_t * ret);

mcpc_errcode_t mcpc_toolprop_get_u8 (const mcpc_toolprop_t * toolprop, u8_t * ret);

mcpc_errcode_t mcpc_toolprop_get_i16 (const mcpc_toolprop_t * toolprop, i16_t * ret);

mcpc_errcode_t mcpc_toolprop_get_u16 (const mcpc_toolprop_t * toolprop, u16_t * ret);

mcpc_errcode_t mcpc_toolprop_get_i32 (const mcpc_toolprop_t * toolprop, i32_t * ret);

mcpc_errcode_t mcpc_toolprop_get_u32 (const mcpc_toolprop_t * toolprop, u32_t * ret);

mcpc_errcode_t mcpc_toolprop_get_i64 (const mcpc_toolprop_t * toolprop, i64_t * ret);

mcpc_errcode_t mcpc_toolprop_get_u64 (const mcpc_toolprop_t * toolprop, u64_t * ret);

mcpc_errcode_t mcpc_toolprop_get_func (const mcpc_toolprop_t * toolprop, void *ret);

mcpc_errcode_t mcpc_toolprop_set_i8s (mcpc_toolprop_t * toolprop, const i8_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_toolprop_set_u8s (mcpc_toolprop_t * toolprop, const u8_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_toolprop_set_i16s (mcpc_toolprop_t * toolprop, const i16_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_toolprop_set_u16s (mcpc_toolprop_t * toolprop, const u16_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_toolprop_set_i32s (mcpc_toolprop_t * toolprop, const i32_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_toolprop_set_u32s (mcpc_toolprop_t * toolprop, const u32_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_toolprop_set_i64s (mcpc_toolprop_t * toolprop, const i64_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_toolprop_set_u64s (mcpc_toolprop_t * toolprop, const u64_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_toolprop_set_u8str (mcpc_toolprop_t * toolprop, const char8_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_toolprop_get_i8s (const mcpc_toolprop_t * toolprop, i8_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_get_u8s (const mcpc_toolprop_t * toolprop, u8_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_get_i16s (const mcpc_toolprop_t * toolprop, i16_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_get_u16s (const mcpc_toolprop_t * toolprop, u16_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_get_i32s (const mcpc_toolprop_t * toolprop, i32_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_get_u32s (const mcpc_toolprop_t * toolprop, u32_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_get_i64s (const mcpc_toolprop_t * toolprop, i64_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_get_u64s (const mcpc_toolprop_t * toolprop, u64_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_toolprop_get_u8str (const mcpc_toolprop_t * toolprop, char8_t * ret, size_t ret_cap,
					size_t *ret_len);

const mcpc_toolproppool_t *mcpc_tool_get_toolproppool (const mcpc_tool_t * tool);

// -------------------------- toolproppool --------------------------

size_t mcpc_toolproppool_get_len (const mcpc_toolproppool_t * toolproppool);

const mcpc_toolprop_t *mcpc_toolproppool_get (const mcpc_toolproppool_t * toolproppool, size_t idx);

// ------------------------------ tool ------------------------------

mcpc_errcode_t mcpc_tool_getref_name (const mcpc_tool_t * tool, const char8_t ** ret, size_t *ret_len);

mcpc_errcode_t mcpc_tool_getref_desc (const mcpc_tool_t * tool, const char8_t ** ret, size_t *ret_len);

void mcpc_tool_free (mcpc_tool_t * tool);

// ---------------------------- toolpool ----------------------------

mcpc_toolpool_t *mcpc_toolpool_new ();

void mcpc_toolpool_free (mcpc_toolpool_t * toolpool);

void mcpc_toolpool_addcpy (mcpc_toolpool_t * toolpool, const mcpc_tool_t * tool);

void mcpc_toolpool_addfre (mcpc_toolpool_t * toolpool, mcpc_tool_t * tool);

size_t mcpc_toolpool_get_len (const mcpc_toolpool_t * toolpool);

const mcpc_tool_t *mcpc_toolpool_get (const mcpc_toolpool_t * toolpool, size_t idx);

const mcpc_tool_t *mcpc_toolpool_getbyname (const mcpc_toolpool_t * toolpool, const char8_t * name, size_t name_len);


#endif
