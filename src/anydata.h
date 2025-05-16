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

#ifndef h_anydata
#define h_anydata

#include <stddef.h>

#include "ext_stdint.h"

#include <mcpc/_c23_keywords.h>
#include <mcpc/_c23_uchar.h>

#include <mcpc/anydata.h>
#include <mcpc/errcode.h>

// ---------------------------- anydata ----------------------------

#ifdef MCPC_C23GIVUP_FIXENUM
enum mcpc_anydata_flags
#else
enum mcpc_anydata_flags:u16_t
#endif
{
  ANYDATA_FL_REQUIRED = 1 << 0,
  ANYDATA_FL_TOOL = 1 << 1,
  ANYDATA_FL_TOOLPROP = 1 << 2,
  ANYDATA_FL_RSC = 1 << 3,
  ANYDATA_FL_PRMPT = 1 << 4,
  ANYDATA_FL_PRMPTARG = 1 << 5,
  ANYDATA_FL_USRCBRES_TOOLCALL = 1 << 6,
  ANYDATA_FL_USRCBRES_TOOLCALL_TXTCTN = 1 << 7,
  ANYDATA_FL_USRCBRES_TOOLCALL_IMGCTN = 1 << 8,
  ANYDATA_FL_USRCBRES_PRMPTCALL = 1 << 9,
  ANYDATA_FL_USRCBRES_PRMPTCALL_ASSIST = 1 << 10,
  ANYDATA_FL_COMPLT = 1 << 11,
  ANYDATA_FL_PRMPTARGHINT = 1 << 12,
};
typedef enum mcpc_anydata_flags mcpc_anydata_flags_t;

struct mcpc_anydata
{
  u8_t meta1_len;
  mcpc_mime_t data_mime;
  mcpc_anytype_t data_typ;
  mcpc_anydata_flags_t flags;
  u16_t meta2_len;
  size_t data_len;
  const char8_t *meta1;
  const char8_t *meta2;
  mcpc_anypool_t *chd_pool;
  union
  {
    uintmax_t data_intlk;
    uintptr_t *data_arrlk;
  };
};

mcpc_anydata_t *mcpc_anydata_new ();

mcpc_anydata_t *mcpc_anydata_new_typ (mcpc_anytype_t typ);

mcpc_anydata_t *mcpc_anydata_new_meta1_meta2 (const char8_t * meta1,
					      const size_t meta1_len, const char8_t * meta2, const size_t meta2_len);

mcpc_anydata_t *mcpc_anydata_new_meta1nt_meta2nt (const char8_t * meta1nt, const char8_t * meta2nt);

mcpc_anydata_t *mcpc_anydata_new_typ_meta1 (mcpc_anytype_t typ, const char8_t * meta1, const size_t meta1_len);

mcpc_anydata_t *mcpc_anydata_new_typ_meta1_meta2 (mcpc_anytype_t typ,
						  const char8_t * meta1,
						  const size_t meta1_len, const char8_t * meta2,
						  const size_t meta2_len);

mcpc_anydata_t *mcpc_anydata_new_typ_meta1nt_meta2nt (mcpc_anytype_t typ,
						      const char8_t * meta1nt, const char8_t * meta2nt);

void mcpc_anydata_free (mcpc_anydata_t * data);

void mcpc_anydata_copy (mcpc_anydata_t * dest_data, const mcpc_anydata_t * src_data);

mcpc_errcode_t mcpc_anydata_set_meta1nt (mcpc_anydata_t * anydata, const char8_t * meta1);

mcpc_errcode_t mcpc_anydata_set_i8 (mcpc_anydata_t * anydata, i8_t val);

mcpc_errcode_t mcpc_anydata_set_u8 (mcpc_anydata_t * anydata, u8_t val);

mcpc_errcode_t mcpc_anydata_set_i16 (mcpc_anydata_t * anydata, i16_t val);

mcpc_errcode_t mcpc_anydata_set_u16 (mcpc_anydata_t * anydata, u16_t val);

mcpc_errcode_t mcpc_anydata_set_i32 (mcpc_anydata_t * anydata, i32_t val);

mcpc_errcode_t mcpc_anydata_set_u32 (mcpc_anydata_t * anydata, u32_t val);

mcpc_errcode_t mcpc_anydata_set_i64 (mcpc_anydata_t * anydata, i64_t val);

mcpc_errcode_t mcpc_anydata_set_u64 (mcpc_anydata_t * anydata, u64_t val);

mcpc_errcode_t mcpc_anydata_set_func (mcpc_anydata_t * anydata, void *val);

mcpc_errcode_t mcpc_anydata_get_i8 (const mcpc_anydata_t * anydata, i8_t * ret);

mcpc_errcode_t mcpc_anydata_get_u8 (const mcpc_anydata_t * anydata, u8_t * ret);

mcpc_errcode_t mcpc_anydata_get_i16 (const mcpc_anydata_t * anydata, i16_t * ret);

mcpc_errcode_t mcpc_anydata_get_u16 (const mcpc_anydata_t * anydata, u16_t * ret);

mcpc_errcode_t mcpc_anydata_get_i32 (const mcpc_anydata_t * anydata, i32_t * ret);

mcpc_errcode_t mcpc_anydata_get_u32 (const mcpc_anydata_t * anydata, u32_t * ret);

mcpc_errcode_t mcpc_anydata_get_i64 (const mcpc_anydata_t * anydata, i64_t * ret);

mcpc_errcode_t mcpc_anydata_get_u64 (const mcpc_anydata_t * anydata, u64_t * ret);

mcpc_errcode_t mcpc_anydata_get_func (const mcpc_anydata_t * anydata, void *ret);

mcpc_errcode_t mcpc_anydata_set_i8s (mcpc_anydata_t * anydata, const i8_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_anydata_set_u8s (mcpc_anydata_t * anydata, const u8_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_anydata_set_i16s (mcpc_anydata_t * anydata, const i16_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_anydata_set_u16s (mcpc_anydata_t * anydata, const u16_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_anydata_set_i32s (mcpc_anydata_t * anydata, const i32_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_anydata_set_u32s (mcpc_anydata_t * anydata, const u32_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_anydata_set_i64s (mcpc_anydata_t * anydata, const i64_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_anydata_set_u64s (mcpc_anydata_t * anydata, const u64_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_anydata_set_u8str (mcpc_anydata_t * anydata, const char8_t * arr, size_t arr_len);

mcpc_errcode_t mcpc_anydata_get_i8s (const mcpc_anydata_t * anydata, i8_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_get_u8s (const mcpc_anydata_t * anydata, u8_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_get_i16s (const mcpc_anydata_t * anydata, i16_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_get_u16s (const mcpc_anydata_t * anydata, u16_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_get_i32s (const mcpc_anydata_t * anydata, i32_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_get_u32s (const mcpc_anydata_t * anydata, u32_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_get_i64s (const mcpc_anydata_t * anydata, i64_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_get_u64s (const mcpc_anydata_t * anydata, u64_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_get_u8str (const mcpc_anydata_t * anydata, char8_t * ret, size_t ret_cap, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_getref_u8str (const mcpc_anydata_t * anydata, const char8_t ** ret, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_getref_meta1 (const mcpc_anydata_t * anydata, const char8_t ** ret, size_t *ret_len);

mcpc_errcode_t mcpc_anydata_getref_meta2 (const mcpc_anydata_t * anydata, const char8_t ** ret, size_t *ret_len);

const mcpc_anydata_t *mcpc_anydata_get_child (const mcpc_anydata_t * anydata, size_t idx);

void mcpc_anydata_add_child (mcpc_anydata_t * data, mcpc_anydata_t * child);

void mcpc_anydata_addcpy_child (mcpc_anydata_t * data, const mcpc_anydata_t * child);

// ---------------------------- anypool ----------------------------

#ifdef MCPC_C23GIVUP_FIXENUM
enum mcpc_anypool_flags
#else
enum mcpc_anypool_flags:u16_t
#endif
{
  ANYPOOL_FL_USRCBRES_TOOLCALL = 1 << 0,
  ANYPOOL_FL_USRCBRES_TOOLCALL_ERROR = 1 << 1,
  ANYPOOL_FL_USRCBRES_PRMPTCALL = 1 << 2,
};
typedef enum mcpc_anypool_flags mcpc_anypool_flags_t;

struct mcpc_anypool
{
  mcpc_anypool_flags_t flags;
  size_t cap;
  size_t len;
  const mcpc_anydata_t *head;
};

constexpr static size_t mcpc_anypool_gamt = 8;

const mcpc_anydata_t *mcpc_anypool_get (const mcpc_anypool_t * anypool, size_t idx);

const mcpc_anydata_t *mcpc_anypool_getbymeta1 (const mcpc_anypool_t * anypool, const char8_t * meta1, size_t meta1_len);

const mcpc_anydata_t *mcpc_anypool_getbymeta1nt (const mcpc_anypool_t * pool, const char8_t * meta1nt);

mcpc_anypool_t *mcpc_anypool_new ();

void mcpc_anypool_free (mcpc_anypool_t * anypool);

void mcpc_anypool_copy (mcpc_anypool_t * dest_pool, const mcpc_anypool_t * src_pool);

void mcpc_anypool_addfre (mcpc_anypool_t * anypool, mcpc_anydata_t * tmp_data);

void mcpc_anypool_addcpy (mcpc_anypool_t * anypool, const mcpc_anydata_t * tmp_data);

#endif
