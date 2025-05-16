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

#include "tool.h"

#include "ext_string.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "errcode.h"
#include "alloc.h"
#include "anydata.h"

// ------------------------------ toolprop ------------------------------

MCPC_API mcpc_toolprop_t *
mcpc_toolprop_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len,
		   mcpc_anytype_t typ)
{
  mcpc_anydata_t *hp = mcpc_anydata_new_typ_meta1_meta2 (typ, name, name_len, desc, desc_len);

  hp->flags |= ANYDATA_FL_REQUIRED;
  hp->flags |= ANYDATA_FL_TOOLPROP;

  return hp;
}

MCPC_API mcpc_toolprop_t *
mcpc_toolprop_new2 (const char8_t *nament, const char8_t *descnt, mcpc_anytype_t typ)
{
  return mcpc_toolprop_new (nament, strlen ((const char *) nament), descnt, strlen ((const char *) descnt), typ);
}

void
mcpc_toolprop_free (mcpc_toolprop_t *toolprop)
{
  mcpc_anydata_free ((mcpc_anydata_t *) toolprop);
}

mcpc_errcode_t
mcpc_toolprop_getref_name (const mcpc_toolprop_t *toolprop, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_meta1 (toolprop, ret, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_getref_desc (const mcpc_toolprop_t *toolprop, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_meta2 (toolprop, ret, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_get_data_type (const mcpc_toolprop_t *toolprop, mcpc_anytype_t *ret)
{
  bug_if_nullptr (toolprop);
  bug_if_nullptr (ret);
  *ret = ((const mcpc_anydata_t *) toolprop)->data_typ;
  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_toolprop_set_nament (mcpc_toolprop_t *toolprop, const char8_t *name)
{
  return mcpc_anydata_set_meta1nt (toolprop, name);
}

mcpc_errcode_t
mcpc_toolprop_set_i8 (mcpc_toolprop_t *toolprop, i8_t val)
{
  return mcpc_anydata_set_i8 (toolprop, val);
}

mcpc_errcode_t
mcpc_toolprop_set_u8 (mcpc_toolprop_t *toolprop, u8_t val)
{
  return mcpc_anydata_set_u8 (toolprop, val);
}

mcpc_errcode_t
mcpc_toolprop_set_i16 (mcpc_toolprop_t *toolprop, i16_t val)
{
  return mcpc_anydata_set_i16 (toolprop, val);
}

mcpc_errcode_t
mcpc_toolprop_set_u16 (mcpc_toolprop_t *toolprop, u16_t val)
{
  return mcpc_anydata_set_u16 (toolprop, val);
}

mcpc_errcode_t
mcpc_toolprop_set_i32 (mcpc_toolprop_t *toolprop, i32_t val)
{
  return mcpc_anydata_set_i32 (toolprop, val);
}

mcpc_errcode_t
mcpc_toolprop_set_u32 (mcpc_toolprop_t *toolprop, u32_t val)
{
  return mcpc_anydata_set_u32 (toolprop, val);
}


mcpc_errcode_t
mcpc_toolprop_set_i64 (mcpc_toolprop_t *toolprop, i64_t val)
{
  return mcpc_anydata_set_i64 (toolprop, val);
}


mcpc_errcode_t
mcpc_toolprop_set_u64 (mcpc_toolprop_t *toolprop, u64_t val)
{
  return mcpc_anydata_set_u64 (toolprop, val);
}


mcpc_errcode_t
mcpc_toolprop_set_func (mcpc_toolprop_t *toolprop, void *val)
{
  return mcpc_anydata_set_func (toolprop, val);
}


mcpc_errcode_t
mcpc_toolprop_get_i8 (const mcpc_toolprop_t *toolprop, i8_t *ret)
{
  return mcpc_anydata_get_i8 (toolprop, ret);
}


mcpc_errcode_t
mcpc_toolprop_get_u8 (const mcpc_toolprop_t *toolprop, u8_t *ret)
{
  return mcpc_anydata_get_u8 (toolprop, ret);
}


mcpc_errcode_t
mcpc_toolprop_get_i16 (const mcpc_toolprop_t *toolprop, i16_t *ret)
{
  return mcpc_anydata_get_i16 (toolprop, ret);
}


mcpc_errcode_t
mcpc_toolprop_get_u16 (const mcpc_toolprop_t *toolprop, u16_t *ret)
{
  return mcpc_anydata_get_u16 (toolprop, ret);
}


mcpc_errcode_t
mcpc_toolprop_get_i32 (const mcpc_toolprop_t *toolprop, i32_t *ret)
{
  return mcpc_anydata_get_i32 (toolprop, ret);
}


mcpc_errcode_t
mcpc_toolprop_get_u32 (const mcpc_toolprop_t *toolprop, u32_t *ret)
{
  return mcpc_anydata_get_u32 (toolprop, ret);
}


mcpc_errcode_t
mcpc_toolprop_get_i64 (const mcpc_toolprop_t *toolprop, i64_t *ret)
{
  return mcpc_anydata_get_i64 (toolprop, ret);
}


mcpc_errcode_t
mcpc_toolprop_get_u64 (const mcpc_toolprop_t *toolprop, u64_t *ret)
{
  return mcpc_anydata_get_u64 (toolprop, ret);
}



mcpc_errcode_t
mcpc_toolprop_set_i8s (mcpc_toolprop_t *toolprop, const i8_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_i8s (toolprop, arr, arr_len);
}


mcpc_errcode_t
mcpc_toolprop_set_u8s (mcpc_toolprop_t *toolprop, const u8_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_u8s (toolprop, arr, arr_len);
}

mcpc_errcode_t
mcpc_toolprop_set_i16s (mcpc_toolprop_t *toolprop, const i16_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_i16s (toolprop, arr, arr_len);
}

mcpc_errcode_t
mcpc_toolprop_set_u16s (mcpc_toolprop_t *toolprop, const u16_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_u16s (toolprop, arr, arr_len);
}

mcpc_errcode_t
mcpc_toolprop_set_i32s (mcpc_toolprop_t *toolprop, const i32_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_i32s (toolprop, arr, arr_len);
}

mcpc_errcode_t
mcpc_toolprop_set_u32s (mcpc_toolprop_t *toolprop, const u32_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_u32s (toolprop, arr, arr_len);
}

mcpc_errcode_t
mcpc_toolprop_set_i64s (mcpc_toolprop_t *toolprop, const i64_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_i64s (toolprop, arr, arr_len);
}

mcpc_errcode_t
mcpc_toolprop_set_u64s (mcpc_toolprop_t *toolprop, const u64_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_u64s (toolprop, arr, arr_len);
}

mcpc_errcode_t
mcpc_toolprop_set_u8str (mcpc_toolprop_t *toolprop, const char8_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_u8str (toolprop, arr, arr_len);
}

mcpc_errcode_t
mcpc_toolprop_get_i8s (const mcpc_toolprop_t *toolprop, i8_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_i8s (toolprop, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_get_u8s (const mcpc_toolprop_t *toolprop, u8_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_u8s (toolprop, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_get_i16s (const mcpc_toolprop_t *toolprop, i16_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_i16s (toolprop, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_get_u16s (const mcpc_toolprop_t *toolprop, u16_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_u16s (toolprop, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_get_i32s (const mcpc_toolprop_t *toolprop, i32_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_i32s (toolprop, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_get_u32s (const mcpc_toolprop_t *toolprop, u32_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_u32s (toolprop, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_get_i64s (const mcpc_toolprop_t *toolprop, i64_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_i64s (toolprop, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_get_u64s (const mcpc_toolprop_t *toolprop, u64_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_u64s (toolprop, ret, ret_cap, ret_len);
}

mcpc_errcode_t
mcpc_toolprop_get_u8str (const mcpc_toolprop_t *toolprop, char8_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_u8str (toolprop, ret, ret_cap, ret_len);
}


// ---------------------------- toolproppool ----------------------------

size_t
mcpc_toolproppool_get_len (const mcpc_toolproppool_t *toolproppool)
{
  bug_if_nullptr (toolproppool);
  size_t ret = 0;
  ret = ((const mcpc_anypool_t *) toolproppool)->len;
  return ret;
}

const mcpc_toolprop_t *
mcpc_toolproppool_get (const mcpc_toolproppool_t *toolproppool, size_t idx)
{
  bug_if_nullptr (toolproppool);
  return ((mcpc_anypool_t *) toolproppool)->head + idx;
}


// ------------------------------ tool ------------------------------

MCPC_API mcpc_tool_t *
mcpc_tool_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len)
{
  mcpc_anydata_t *hp = mcpc_anydata_new_meta1_meta2 (name, name_len, desc, desc_len);

  hp->flags |= ANYDATA_FL_TOOL;

  return hp;
}

MCPC_API mcpc_tool_t *
mcpc_tool_new2 (const char8_t *nament, const char8_t *descnt)
{
  return mcpc_tool_new (nament, strlen ((const char *) nament), descnt, strlen ((const char *) descnt));
}

void
mcpc_tool_free (mcpc_tool_t *tool)
{
  mcpc_anydata_free ((mcpc_anydata_t *) tool);
}

mcpc_errcode_t
mcpc_tool_getref_name (const mcpc_tool_t *tool, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_meta1 (tool, ret, ret_len);
}

mcpc_errcode_t
mcpc_tool_getref_desc (const mcpc_tool_t *tool, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_meta2 (tool, ret, ret_len);
}

MCPC_API mcpc_errcode_t
mcpc_tool_get_call_cb (const mcpc_tool_t *tool, mcpc_tcallcb_t *ret)
{
  return mcpc_anydata_get_func (tool, ret);
}

MCPC_API mcpc_errcode_t
mcpc_tool_set_call_cb (mcpc_tool_t *tool, mcpc_tcallcb_t cb)
{
  mcpc_anydata_set_func (tool, cb);
  return MCPC_EC_0;
}

MCPC_API void
mcpc_tool_addfre_toolprop (mcpc_tool_t *tool, mcpc_toolprop_t *toolprop)
{
  mcpc_anydata_add_child (tool, toolprop);	// TODO return EC
}

MCPC_API void
mcpc_tool_addcpy_toolprop (mcpc_tool_t *tool, mcpc_toolprop_t *toolprop)
{
  mcpc_anydata_addcpy_child (tool, toolprop);	// TODO return EC
}

MCPC_API const mcpc_toolprop_t *
mcpc_tool_get_toolprop (const mcpc_tool_t *tool, size_t idx)
{
  return mcpc_anydata_get_child (tool, idx);
}

size_t
mcpc_tool_get_toolprop_len (const mcpc_tool_t *tool)
{
  bug_if_nullptr (tool);
  mcpc_anydata_t *tool_imp = (mcpc_anydata_t *) tool;
  if (tool_imp->chd_pool == nullptr)
    return 0;
  return tool_imp->chd_pool->len;
}

MCPC_API const mcpc_toolprop_t *
mcpc_tool_get_next_toolprop (const mcpc_tool_t *tool)
{
  bug_if_nullptr (tool);

  static size_t idx = 0;

  const mcpc_anypool_t *pool = tool->chd_pool;
  if (pool == nullptr)
    return nullptr;

  const size_t pool_len = pool->len;
  if (pool_len == 0)
    return nullptr;

  if (idx == pool_len)		// TODO  MT-SAFE
    {
      idx = 0;
      return nullptr;
    }

  const mcpc_anydata_t *ret = pool->head + idx;
  idx += 1;

  return ret;
}

const mcpc_toolprop_t *
mcpc_tool_getbynament_toolprop (const mcpc_tool_t *tool, const char8_t *tprop_nament)
{
  const mcpc_anydata_t *chd = mcpc_anypool_getbymeta1nt (tool->chd_pool, tprop_nament);
  return (mcpc_toolprop_t *) chd;
}

MCPC_API mcpc_errcode_t
mcpc_tool_get_tpropval_i32 (const mcpc_tool_t *tool, const char8_t *tprop_nament, i32_t *ret)
{
  bug_if_nullptr (tool);
  bug_if_nullptr (tprop_nament);
  bug_if_nullptr (ret);
  const mcpc_toolprop_t *chd = mcpc_tool_getbynament_toolprop (tool, tprop_nament);
  if (chd == nullptr)
    return MCPC_EC_TOOLPROP_NOTFOUND;

  return mcpc_toolprop_get_i32 (chd, ret);
}

MCPC_API mcpc_errcode_t
mcpc_tool_get_tpropval_u8str (const mcpc_tool_t *tool, const char8_t *tprop_nament, char8_t *ret,
			      size_t ret_cap, size_t *ret_len)
{
  bug_if_nullptr (tool);
  bug_if_nullptr (tprop_nament);
  bug_if_nullptr (ret);
  const mcpc_toolprop_t *chd = mcpc_tool_getbynament_toolprop (tool, tprop_nament);
  if (chd == nullptr)
    return MCPC_EC_TOOLPROP_NOTFOUND;

  return mcpc_anydata_get_u8str (chd, ret, ret_cap, ret_len);
}

const mcpc_toolproppool_t *
mcpc_tool_get_toolproppool (const mcpc_tool_t *tool)
{
  return tool->chd_pool;
}



// ---------------------------- toolpool ----------------------------

mcpc_toolpool_t *
mcpc_toolpool_new ()
{
  return mcpc_anypool_new ();
}

void
mcpc_toolpool_free (mcpc_toolpool_t *toolpool)
{
  mcpc_anypool_free (toolpool);
}

void
mcpc_toolpool_addcpy (mcpc_toolpool_t *toolpool, const mcpc_tool_t *tool)
{
  mcpc_anypool_addcpy (toolpool, tool);
}

void
mcpc_toolpool_addfre (mcpc_toolpool_t *toolpool, mcpc_tool_t *tool)
{
  mcpc_anypool_addfre (toolpool, tool);
}

size_t
mcpc_toolpool_get_len (const mcpc_toolpool_t *toolpool)
{
  bug_if_nullptr (toolpool);
  size_t ret = 0;
  ret = ((const mcpc_anypool_t *) toolpool)->len;
  return ret;
}


const mcpc_tool_t *
mcpc_toolpool_get (const mcpc_toolpool_t *toolpool, size_t idx)
{
  return mcpc_anypool_get (toolpool, idx);
}

const mcpc_tool_t *
mcpc_toolpool_getbyname (const mcpc_toolpool_t *toolpool, const char8_t *name, size_t name_len)
{
  return mcpc_anypool_getbymeta1 (toolpool, name, name_len);
}
