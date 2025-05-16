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

#include "anydata.h"

#include "ext_string.h"

#include <mcpc/errcode.h>
#include "alloc.h"
#include "errcode.h"

const mcpc_anydata_t *mcpc_anypool_getbymeta1 (const mcpc_anypool_t * anypool, const char8_t * meta1, size_t meta1_len);
const mcpc_anydata_t *mcpc_anypool_getbymeta1nt (const mcpc_anypool_t * anypool, const char8_t * meta1nt);

constexpr static size_t mcpc_anypool_gamt = 8;

// ---------------------------- anydata ----------------------------

mcpc_anydata_t *
mcpc_anydata_new ()
{
  mcpc_anydata_t *hp_data = mcpc_calloc (sizeof (mcpc_anydata_t));
  return hp_data;
}

mcpc_anydata_t *
mcpc_anydata_new_typ (mcpc_anytype_t typ)
{
  mcpc_anydata_t *hp_data = mcpc_calloc (sizeof (mcpc_anydata_t));
  hp_data->data_typ = typ;
  return hp_data;
}

mcpc_anydata_t *
mcpc_anydata_new_meta1_meta2 (const char8_t *meta1, const size_t meta1_len, const char8_t *meta2, const size_t meta2_len)
{
  mcpc_assert (meta1_len <= (size_t) UINT8_MAX, MCPC_EC_ANYDATA_LONGMETA1);
  mcpc_assert (meta2_len <= (size_t) UINT16_MAX, MCPC_EC_ANYDATA_LONGMETA2);

  mcpc_anydata_t *hp_data = mcpc_calloc (sizeof (mcpc_anydata_t));

  void *hp_meta1 = mcpc_alloc (meta1_len);
  memcpy (hp_meta1, meta1, meta1_len);
  hp_data->meta1 = hp_meta1;
  hp_data->meta1_len = (u8_t) meta1_len;

  if (meta2_len > 0)
    {
      void *hp_meta2 = mcpc_alloc (meta2_len);
      memcpy (hp_meta2, meta2, meta2_len);
      hp_data->meta2 = hp_meta2;
      hp_data->meta2_len = (u8_t) meta2_len;
    }

  return hp_data;
}

mcpc_anydata_t *
mcpc_anydata_new_meta1nt_meta2nt (const char8_t *meta1nt, const char8_t *meta2nt)
{
  return mcpc_anydata_new_meta1_meta2 (meta1nt, u8strlen (meta1nt), meta2nt, u8strlen (meta2nt));
}


mcpc_anydata_t *
mcpc_anydata_new_typ_meta1 (mcpc_anytype_t typ, const char8_t *meta1, const size_t meta1_len)
{
  mcpc_anydata_t *hp_data = mcpc_anydata_new_meta1_meta2 (meta1, meta1_len, nullptr, 0);
  hp_data->data_typ = typ;
  return hp_data;
}

mcpc_anydata_t *
mcpc_anydata_new_typ_meta1_meta2 (mcpc_anytype_t typ, const char8_t *meta1, const size_t meta1_len, const char8_t *meta2,
				const size_t meta2_len)
{
  mcpc_anydata_t *hp_data = mcpc_anydata_new_meta1_meta2 (meta1, meta1_len, meta2, meta2_len);
  hp_data->data_typ = typ;
  return hp_data;
}


mcpc_anydata_t *
mcpc_anydata_new_typ_meta1nt_meta2nt (mcpc_anytype_t typ, const char8_t *meta1nt, const char8_t *meta2nt)
{
  return mcpc_anydata_new_typ_meta1_meta2 (typ, meta1nt, u8strlen (meta1nt), meta2nt, u8strlen (meta2nt));
}

void
mcpc_anydata_mbfree (mcpc_anydata_t *data)
{
  bug_if (data == nullptr);

  if (data->meta1 != nullptr)
    {
      free ((void *) data->meta1);
      data->meta1_len = 0;
    }

  if (data->meta2 != nullptr)
    {
      free ((void *) data->meta2);
      data->meta2_len = 0;
    }

  if (data->chd_pool != nullptr)
    {
      mcpc_anypool_free (data->chd_pool);
    }

  if (mcpc_anytype_is_arrlike (data->data_typ))
    {
      free ((void *) data->data_arrlk);
      data->data_len = 0;
    }
}

void
mcpc_anydata_free (mcpc_anydata_t *data)
{
  mcpc_anydata_mbfree (data);
  free (data);
}

void
mcpc_anydata_copy (mcpc_anydata_t *dest_data, const mcpc_anydata_t *src_data)
{
  bug_if (dest_data == nullptr);
  bug_if (src_data == nullptr);

  // make sure inited
  memset (dest_data, 0, sizeof (mcpc_anydata_t));

  if (src_data->meta1_len > 0 && src_data->meta1 != nullptr)
    {
      void *hp_meta1 = mcpc_alloc (src_data->meta1_len);
      memcpy (hp_meta1, src_data->meta1, src_data->meta1_len);
      dest_data->meta1 = hp_meta1;
      dest_data->meta1_len = src_data->meta1_len;
    }

  if (src_data->meta2_len > 0 && src_data->meta2 != nullptr)
    {
      void *hp_meta2 = mcpc_alloc (src_data->meta2_len);
      memcpy (hp_meta2, src_data->meta2, src_data->meta2_len);
      dest_data->meta2 = hp_meta2;
      dest_data->meta2_len = src_data->meta2_len;
    }

  if (false);
  else if (mcpc_anytype_is_arrlike (src_data->data_typ) && src_data->data_len > 0)
    {
      dest_data->data_arrlk = mcpc_alloc (src_data->data_len);
      memcpy (dest_data->data_arrlk, src_data->data_arrlk, src_data->data_len);
    }
  else if (mcpc_anytype_is_intlike (src_data->data_typ))
    dest_data->data_intlk = src_data->data_intlk;

  if (src_data->chd_pool != nullptr)
    {
      dest_data->chd_pool = mcpc_anypool_new ();
      mcpc_anypool_copy (dest_data->chd_pool, src_data->chd_pool);
    }

  dest_data->data_typ = src_data->data_typ;
  dest_data->data_len = src_data->data_len;
  dest_data->flags = src_data->flags;
  dest_data->data_mime = src_data->data_mime;

}


// mcpc_errcode_t
// mcpc_anydata_set_call_cb (mcpc_anydata_t *data, mcpc_tcallcb_t cb)
// {
//   bug_if_nullptr (data);
//   data->call_cb = cb;
//   return MCPC_EC_0;
// }

void
mcpc_anydata_add_child (mcpc_anydata_t *data, mcpc_anydata_t *child)
{
  bug_if_nullptr (data);
  bug_if_nullptr ((void *) child);

  if (data->chd_pool == nullptr)
    {
      data->chd_pool = mcpc_anypool_new ();
    }
  mcpc_anypool_addfre (data->chd_pool, child);
}

void
mcpc_anydata_addcpy_child (mcpc_anydata_t *data, const mcpc_anydata_t *child)
{
  bug_if_nullptr (data);
  bug_if_nullptr ((void *) child);

  if (data->chd_pool == nullptr)
    {
      data->chd_pool = mcpc_anypool_new ();
    }
  mcpc_anypool_addcpy (data->chd_pool, child);
}

const mcpc_anydata_t *
mcpc_anydata_get_child (const mcpc_anydata_t *anydata, size_t idx)
{
  bug_if (anydata == nullptr);
  return mcpc_anypool_get (anydata->chd_pool, idx);
}

mcpc_errcode_t
mcpc_anydata_set_meta1 (mcpc_anydata_t *anydata, const char8_t *meta1, size_t meta1_len)
{
  bug_if_nullptr (anydata);
  bug_if_nullptr ((void *) meta1);

  if (meta1_len == 0)
    {
      free ((void *) anydata->meta1);
      anydata->meta1 = nullptr;
      anydata->meta1_len = 0;
      return MCPC_EC_0;
    }

  if (meta1_len > (size_t) UINT8_MAX)
    {
      return MCPC_EC_ANYDATA_LONGMETA1;
    }

  anydata->meta1 = mcpc_realloc ((void *) anydata->meta1, meta1_len);
  memcpy ((void *) anydata->meta1, meta1, meta1_len);
  anydata->meta1_len = (u8_t) meta1_len;

  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_anydata_set_meta1nt (mcpc_anydata_t *anydata, const char8_t *meta1)
{
  size_t meta1_len = u8strlen (meta1);
  return mcpc_anydata_set_meta1 (anydata, meta1, meta1_len);
}

mcpc_errcode_t
mcpc_anydata_release_data (mcpc_anydata_t *anydata)
{
  if (!mcpc_anytype_is_arrlike (anydata->data_typ))
    return MCPC_EC_0;

  if (anydata->data_len == 0)
    return MCPC_EC_0;

  free (anydata->data_arrlk);
  anydata->data_len = 0;

  return MCPC_EC_0;
}


mcpc_errcode_t
mcpc_anydata_set_intlk (mcpc_anydata_t *anydata, mcpc_anytype_t typ, const void *val)
{
  bug_if_nullptr (anydata);

  if (mcpc_anytype_is_arrlike (anydata->data_typ))
    mcpc_anydata_release_data (anydata);

  if (false);
  else if (typ == MCPC_I8 || typ == MCPC_U8)
    anydata->data_intlk = (uintmax_t) (*((u8_t *) val));
  else if (typ == MCPC_I16 || typ == MCPC_U16)
    anydata->data_intlk = (uintmax_t) (*((u16_t *) val));
  else if (typ == MCPC_I32 || typ == MCPC_U32)
    anydata->data_intlk = (uintmax_t) (*((u32_t *) val));
  else if (typ == MCPC_I64 || typ == MCPC_U64)
    anydata->data_intlk = (uintmax_t) (*((u64_t *) val));
  else if (typ == MCPC_FUNC)
    anydata->data_intlk = (uintmax_t) (uintptr_t) (val);
  else
    return MCPC_EC_BUG;

  anydata->data_typ = typ;
  anydata->data_len = 1;

  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_anydata_get_intlk (const mcpc_anydata_t *anydata, mcpc_anytype_t typ, void *ret)
{
  bug_if_nullptr (anydata);
  bug_if_nullptr (ret);

  if (anydata->data_typ != typ)
    return MCPC_EC_ANYDATA_NOTFOUND;

  if (false);
  else if (typ == MCPC_I8)
    {
      i8_t *ret_typed = ret;
      *ret_typed = (i8_t) anydata->data_intlk;
    }
  else if (typ == MCPC_U8)
    {
      u8_t *ret_typed = ret;
      *ret_typed = (u8_t) anydata->data_intlk;
    }
  else if (typ == MCPC_I16)
    {
      i16_t *ret_typed = ret;
      *ret_typed = (i16_t) anydata->data_intlk;
    }
  else if (typ == MCPC_U16)
    {
      u16_t *ret_typed = ret;
      *ret_typed = (u16_t) anydata->data_intlk;
    }
  else if (typ == MCPC_I32)
    {
      i32_t *ret_typed = ret;
      *ret_typed = (i32_t) anydata->data_intlk;
    }
  else if (typ == MCPC_U32)
    {
      u32_t *ret_typed = ret;
      *ret_typed = (u32_t) anydata->data_intlk;
    }
  else if (typ == MCPC_I64)
    {
      i64_t *ret_typed = ret;
      *ret_typed = (i64_t) anydata->data_intlk;
    }
  else if (typ == MCPC_U64)
    {
      u64_t *ret_typed = ret;
      *ret_typed = (u64_t) anydata->data_intlk;
    }
  else if (typ == MCPC_FUNC)
    {
      uintptr_t *ret_typed = ret;
      *ret_typed = (uintptr_t) anydata->data_intlk;
    }
  else
    return MCPC_EC_BUG;

  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_anydata_set_arrlk (mcpc_anydata_t *anydata, mcpc_anytype_t typ, const void *arr, size_t arr_len)
{
  bug_if_nullptr (anydata);
  bug_if_nullptr (arr);

  size_t nbytes = 0;

  if (false);
  else if (typ == MCPC_I8S || typ == MCPC_U8S)
    nbytes = arr_len * sizeof (u8_t);
  else if (typ == MCPC_I16S || typ == MCPC_U16S)
    nbytes = arr_len * sizeof (u16_t);
  else if (typ == MCPC_I32S || typ == MCPC_U32S)
    nbytes = arr_len * sizeof (u32_t);
  else if (typ == MCPC_I64S || typ == MCPC_U64S)
    nbytes = arr_len * sizeof (u64_t);
  else if (typ == MCPC_U8STR)
    nbytes = arr_len * sizeof (char8_t);
  else
    return MCPC_EC_BUG;

  if (anydata->data_typ == typ)
    {
      anydata->data_arrlk = mcpc_realloc (anydata->data_arrlk, nbytes);
    }
  else
    {
      if (mcpc_anytype_is_arrlike (anydata->data_typ))
	mcpc_anydata_release_data (anydata);

      anydata->data_typ = typ;
      anydata->data_arrlk = mcpc_alloc (nbytes);
    }
  memcpy (anydata->data_arrlk, arr, nbytes);
  anydata->data_len = arr_len;

  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_anydata_get_arrlk (const mcpc_anydata_t *anydata, mcpc_anytype_t typ, void *ret, size_t ret_cap, size_t *ret_len)
{
  // NOTE ret_len can be nullptr

  if (anydata->data_typ != typ)
    return MCPC_EC_ANYDATA_NOTFOUND;
  if (ret_cap == 0)
    return MCPC_EC_ANYDATA_NOTFOUND;

  size_t nb_el = 0;
  if (false);
  else if (typ == MCPC_I8S || typ == MCPC_U8S)
    nb_el = sizeof (u8_t);
  else if (typ == MCPC_I16S || typ == MCPC_U16S)
    nb_el = sizeof (u16_t);
  else if (typ == MCPC_I32S || typ == MCPC_U32S)
    nb_el = sizeof (u32_t);
  else if (typ == MCPC_I64S || typ == MCPC_U64S)
    nb_el = sizeof (u64_t);
  else if (typ == MCPC_U8STR)
    nb_el = sizeof (char8_t);
  else
    return MCPC_EC_BUG;

  size_t cplen = anydata->data_len;
  if (cplen > ret_cap)
    cplen = ret_cap;

  memcpy (ret, anydata->data_arrlk, cplen * nb_el);
  if (ret_len != nullptr)
    *ret_len = cplen;

  if (ret_cap > cplen)
    {
      char8_t *ret_typed = ret;
      ret_typed[cplen] = 0;
      return MCPC_EC_0;
    }
  else
    {
      return MCPC_EC_BUFCAP;
    }
}

mcpc_errcode_t
mcpc_anydata_set_i8 (mcpc_anydata_t *anydata, i8_t val)
{
  return mcpc_anydata_set_intlk (anydata, MCPC_I8, &val);
}

mcpc_errcode_t
mcpc_anydata_set_u8 (mcpc_anydata_t *anydata, u8_t val)
{
  return mcpc_anydata_set_intlk (anydata, MCPC_U8, &val);
}

mcpc_errcode_t
mcpc_anydata_set_i16 (mcpc_anydata_t *anydata, i16_t val)
{
  return mcpc_anydata_set_intlk (anydata, MCPC_I16, &val);
}

mcpc_errcode_t
mcpc_anydata_set_u16 (mcpc_anydata_t *anydata, u16_t val)
{
  return mcpc_anydata_set_intlk (anydata, MCPC_U16, &val);
}

mcpc_errcode_t
mcpc_anydata_set_i32 (mcpc_anydata_t *anydata, i32_t val)
{
  return mcpc_anydata_set_intlk (anydata, MCPC_I32, &val);
}

mcpc_errcode_t
mcpc_anydata_set_u32 (mcpc_anydata_t *anydata, u32_t val)
{
  return mcpc_anydata_set_intlk (anydata, MCPC_U32, &val);
}

mcpc_errcode_t
mcpc_anydata_set_i64 (mcpc_anydata_t *anydata, i64_t val)
{
  return mcpc_anydata_set_intlk (anydata, MCPC_I64, &val);
}

mcpc_errcode_t
mcpc_anydata_set_u64 (mcpc_anydata_t *anydata, u64_t val)
{
  return mcpc_anydata_set_intlk (anydata, MCPC_U64, &val);
}

mcpc_errcode_t
mcpc_anydata_set_func (mcpc_anydata_t *anydata, void *val)
{
  return mcpc_anydata_set_intlk (anydata, MCPC_FUNC, val);
}

mcpc_errcode_t
mcpc_anydata_get_i8 (const mcpc_anydata_t *anydata, i8_t *ret)
{
  return mcpc_anydata_get_intlk (anydata, MCPC_I8, ret);
}

mcpc_errcode_t
mcpc_anydata_get_u8 (const mcpc_anydata_t *anydata, u8_t *ret)
{
  return mcpc_anydata_get_intlk (anydata, MCPC_U8, ret);
}

mcpc_errcode_t
mcpc_anydata_get_i16 (const mcpc_anydata_t *anydata, i16_t *ret)
{
  return mcpc_anydata_get_intlk (anydata, MCPC_I16, ret);
}

mcpc_errcode_t
mcpc_anydata_get_u16 (const mcpc_anydata_t *anydata, u16_t *ret)
{
  return mcpc_anydata_get_intlk (anydata, MCPC_U16, ret);
}

mcpc_errcode_t
mcpc_anydata_get_i32 (const mcpc_anydata_t *anydata, i32_t *ret)
{
  return mcpc_anydata_get_intlk (anydata, MCPC_I32, ret);
}

mcpc_errcode_t
mcpc_anydata_get_u32 (const mcpc_anydata_t *anydata, u32_t *ret)
{
  return mcpc_anydata_get_intlk (anydata, MCPC_U32, ret);
}

mcpc_errcode_t
mcpc_anydata_get_i64 (const mcpc_anydata_t *anydata, i64_t *ret)
{
  return mcpc_anydata_get_intlk (anydata, MCPC_I64, ret);
}

mcpc_errcode_t
mcpc_anydata_get_u64 (const mcpc_anydata_t *anydata, u64_t *ret)
{
  return mcpc_anydata_get_intlk (anydata, MCPC_U64, ret);
}

mcpc_errcode_t
mcpc_anydata_get_func (const mcpc_anydata_t *anydata, void *ret)
{
  return mcpc_anydata_get_intlk (anydata, MCPC_FUNC, ret);
}


mcpc_errcode_t
mcpc_anydata_set_i8s (mcpc_anydata_t *anydata, const i8_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_arrlk (anydata, MCPC_I8S, arr, arr_len);
}

mcpc_errcode_t
mcpc_anydata_set_u8s (mcpc_anydata_t *anydata, const u8_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_arrlk (anydata, MCPC_U8S, arr, arr_len);
}

mcpc_errcode_t
mcpc_anydata_set_i16s (mcpc_anydata_t *anydata, const i16_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_arrlk (anydata, MCPC_I16S, arr, arr_len);
}

mcpc_errcode_t
mcpc_anydata_set_u16s (mcpc_anydata_t *anydata, const u16_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_arrlk (anydata, MCPC_U16S, arr, arr_len);
}

mcpc_errcode_t
mcpc_anydata_set_i32s (mcpc_anydata_t *anydata, const i32_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_arrlk (anydata, MCPC_I32S, arr, arr_len);
}

mcpc_errcode_t
mcpc_anydata_set_u32s (mcpc_anydata_t *anydata, const u32_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_arrlk (anydata, MCPC_U32S, arr, arr_len);
}

mcpc_errcode_t
mcpc_anydata_set_i64s (mcpc_anydata_t *anydata, const i64_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_arrlk (anydata, MCPC_I64S, arr, arr_len);
}

mcpc_errcode_t
mcpc_anydata_set_u64s (mcpc_anydata_t *anydata, const u64_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_arrlk (anydata, MCPC_U64S, arr, arr_len);
}

mcpc_errcode_t
mcpc_anydata_set_u8str (mcpc_anydata_t *anydata, const char8_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_arrlk (anydata, MCPC_U8STR, arr, arr_len);
}

mcpc_errcode_t
mcpc_anydata_get_i8s (const mcpc_anydata_t *anydata, i8_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_arrlk (anydata, MCPC_I8S, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_anydata_get_u8s (const mcpc_anydata_t *anydata, u8_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_arrlk (anydata, MCPC_U8S, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_anydata_get_i16s (const mcpc_anydata_t *anydata, i16_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_arrlk (anydata, MCPC_I16S, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_anydata_get_u16s (const mcpc_anydata_t *anydata, u16_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_arrlk (anydata, MCPC_U16S, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_anydata_get_i32s (const mcpc_anydata_t *anydata, i32_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_arrlk (anydata, MCPC_I32S, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_anydata_get_u32s (const mcpc_anydata_t *anydata, u32_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_arrlk (anydata, MCPC_U32S, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_anydata_get_i64s (const mcpc_anydata_t *anydata, i64_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_arrlk (anydata, MCPC_I64S, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_anydata_get_u64s (const mcpc_anydata_t *anydata, u64_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_arrlk (anydata, MCPC_U64S, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_anydata_get_u8str (const mcpc_anydata_t *anydata, char8_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_arrlk (anydata, MCPC_U8STR, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_anydata_getref_u8str (const mcpc_anydata_t *anydata, const char8_t **ret, size_t *ret_len)
{
  bug_if_nullptr (anydata);
  bug_if_nullptr (ret);
  bug_if_nullptr (ret_len);

  *ret = (const char8_t *) anydata->data_arrlk;
  *ret_len = anydata->data_len;

  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_anydata_getref_meta1 (const mcpc_anydata_t *anydata, const char8_t **ret, size_t *ret_len)
{
  bug_if_nullptr (anydata);
  bug_if_nullptr (ret);
  bug_if_nullptr (ret_len);

  *ret = anydata->meta1;
  *ret_len = anydata->meta1_len;

  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_anydata_getref_meta2 (const mcpc_anydata_t *anydata, const char8_t **ret, size_t *ret_len)
{
  bug_if_nullptr (anydata);
  bug_if_nullptr (ret);
  bug_if_nullptr (ret_len);

  *ret = anydata->meta2;
  *ret_len = anydata->meta2_len;

  return MCPC_EC_0;
}

// ---------------------------- anypool ----------------------------

mcpc_anypool_t *
mcpc_anypool_new ()
{
  mcpc_anypool_t *hp_anypool = mcpc_calloc (sizeof (mcpc_anypool_t));
  return hp_anypool;
}

void
mcpc_anypool_free (mcpc_anypool_t *anypool)
{
  bug_if (anypool == nullptr);
  for (size_t i = 0; i < anypool->len; i++)
    {
      mcpc_anydata_t *cur_data = (mcpc_anydata_t *) anypool->head + i;
      mcpc_anydata_mbfree (cur_data);
    }
  if (anypool->cap > 0 && anypool->head != nullptr)
    {
      free ((void *) anypool->head);
    }
  free (anypool);
}


void
mcpc_anypool_set_cap (mcpc_anypool_t *pool, size_t newcap)
{
  size_t newsz = newcap * sizeof (mcpc_anydata_t);
  pool->head = mcpc_realloc ((void *) pool->head, newsz);	// TODO use wrapper
  pool->cap = newcap;
}


void
mcpc_anypool_copy (mcpc_anypool_t *dest_pool, const mcpc_anypool_t *src_pool)
{
  bug_if (dest_pool == nullptr);
  bug_if (src_pool == nullptr);

  // make sure inited. this also means dest's content is insignificant
  memset (dest_pool, 0, sizeof (mcpc_anypool_t));

  mcpc_anypool_set_cap (dest_pool, src_pool->cap);

  for (size_t i = 0; i < src_pool->len; i++)	// TODO ckdadd
    mcpc_anydata_copy ((mcpc_anydata_t *) dest_pool->head + i, src_pool->head + i);

  dest_pool->len = src_pool->len;
}

void
mcpc_anypool_grow (mcpc_anypool_t *pool)
{
  size_t newcap = pool->cap + mcpc_anypool_gamt;
  mcpc_anypool_set_cap (pool, newcap);
}

void
mcpc_anypool_addcpy (mcpc_anypool_t *anypool, const mcpc_anydata_t *tmp_data)
{
  bug_if (anypool == nullptr);
  bug_if (tmp_data == nullptr);

  if (anypool->len + 1 > anypool->cap)
    {
      mcpc_anypool_grow (anypool);
    }
  bug_if (anypool->len + 1 > anypool->cap);

  mcpc_anydata_t *newdata = (mcpc_anydata_t *) (anypool->head + anypool->len);
  mcpc_anydata_copy (newdata, tmp_data);
  anypool->len += 1;
}

void
mcpc_anypool_addfre (mcpc_anypool_t *anypool, mcpc_anydata_t *tmp_data)
{
  mcpc_anypool_addcpy (anypool, tmp_data);
  mcpc_anydata_free (tmp_data);
}

const mcpc_anydata_t *
mcpc_anypool_get (const mcpc_anypool_t *anypool, size_t idx)
{
  bug_if (anypool == nullptr);
  if (idx >= anypool->len)
    return nullptr;
  return anypool->head + idx;
}

const mcpc_anydata_t *
mcpc_anypool_getbymeta1 (const mcpc_anypool_t *anypool, const char8_t *meta1, size_t meta1_len)
{
  bug_if (anypool == nullptr);

  if (meta1 == nullptr || meta1_len == 0)
    return nullptr;

  for (size_t i = 0; i < anypool->len; i++)	// TODO: ckdadd
    {
      const mcpc_anydata_t *cur_data = anypool->head + i;
      if (cur_data->meta1_len > 0)
	{
	  size_t cmpsz = min_size (meta1_len, (size_t) cur_data->meta1_len);
	  if (0 == u8strncmp (cur_data->meta1, meta1, cmpsz))
	    return cur_data;
	}
    }

  return nullptr;
}

const mcpc_anydata_t *
mcpc_anypool_getbymeta1nt (const mcpc_anypool_t *pool, const char8_t *meta1nt)
{
  size_t meta1nt_len = u8strlen (meta1nt);
  return mcpc_anypool_getbymeta1 (pool, meta1nt, meta1nt_len);
}
