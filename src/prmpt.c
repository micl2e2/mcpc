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

#include "prmpt.h"

#include "ext_string.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "errcode.h"
#include "alloc.h"
#include "anydata.h"

/* = = = = = = = = = = = = = = = prmptarg = = = = = = = = = = = = = = = */

MCPC_API mcpc_prmptarg_t *
mcpc_prmptarg_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len)
{
  mcpc_anydata_t *hp = mcpc_anydata_new_meta1_meta2 (name, name_len, desc, desc_len);

  hp->flags |= ANYDATA_FL_REQUIRED;
  hp->flags |= ANYDATA_FL_PRMPTARG;

  hp->data_typ = MCPC_U8STR;

  return hp;
}

MCPC_API mcpc_prmptarg_t *
mcpc_prmptarg_new2 (const char8_t *nament, const char8_t *descnt)
{
  return mcpc_prmptarg_new (nament, u8strlen (nament), descnt, u8strlen (descnt));
}

MCPC_API mcpc_prmptarg_t *
mcpc_prmptarg_new3 (const char8_t *nament)
{
  return mcpc_prmptarg_new (nament, u8strlen (nament), nullptr, 0);
}

void
mcpc_prmptarg_free (mcpc_prmptarg_t *prmptarg)
{
  mcpc_anydata_free ((mcpc_anydata_t *) prmptarg);
}

bool
mcpc_prmptarg_is_required (const mcpc_prmptarg_t *prmptarg)
{
  return prmptarg->flags & ANYDATA_FL_REQUIRED;
}

mcpc_errcode_t
mcpc_prmptarg_getref_name (const mcpc_prmptarg_t *prmptarg, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_meta1 (prmptarg, ret, ret_len);
}

mcpc_errcode_t
mcpc_prmptarg_getref_desc (const mcpc_prmptarg_t *prmptarg, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_meta2 (prmptarg, ret, ret_len);
}

mcpc_errcode_t
mcpc_prmptarg_get_data_type (const mcpc_prmptarg_t *prmptarg, mcpc_anytype_t *ret)
{
  bug_if_nullptr (prmptarg);
  bug_if_nullptr (ret);
  *ret = ((const mcpc_anydata_t *) prmptarg)->data_typ;
  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_prmptarg_set_required (mcpc_prmptarg_t *prmptarg, bool fl)
{
  bug_if_nullptr (prmptarg);

  if (fl)
    {
      prmptarg->flags |= ANYDATA_FL_REQUIRED;
    }
  else
    {
      prmptarg->flags &= (~ANYDATA_FL_REQUIRED);
    }

  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_prmptarg_set_nament (mcpc_prmptarg_t *prmptarg, const char8_t *name)
{
  return mcpc_anydata_set_meta1nt (prmptarg, name);
}

mcpc_errcode_t
mcpc_prmptarg_set_u8str (mcpc_prmptarg_t *prmptarg, const char8_t *arr, size_t arr_len)
{
  return mcpc_anydata_set_u8str (prmptarg, arr, arr_len);
}

MCPC_API mcpc_errcode_t
mcpc_prmptarg_get_u8str (const mcpc_prmptarg_t *prmptarg, char8_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_u8str (prmptarg, ret, ret_cap, ret_len);
}

MCPC_API mcpc_errcode_t
mcpc_prmptarg_getref_u8str (const mcpc_prmptarg_t *prmptarg, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_u8str (prmptarg, ret, ret_len);
}

/* = = = = = = = = = = = = = = = = = prmpt = = = = = = = = = = = = = = = = = */

MCPC_API mcpc_prmpt_t *
mcpc_prmpt_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len)
{
  mcpc_anydata_t *hp = mcpc_anydata_new_meta1_meta2 (name, name_len, desc, desc_len);

  hp->flags |= ANYDATA_FL_PRMPT;

  return hp;
}

MCPC_API mcpc_prmpt_t *
mcpc_prmpt_new2 (const char8_t *nament, const char8_t *descnt)
{
  return mcpc_prmpt_new (nament, strlen ((const char *) nament), descnt, strlen ((const char *) descnt));
}

MCPC_API mcpc_prmpt_t *
mcpc_prmpt_new3 (const char8_t *nament)
{
  return mcpc_prmpt_new (nament, u8strlen (nament), nullptr, 0);
}

void
mcpc_prmpt_free (mcpc_prmpt_t *prmpt)
{
  mcpc_anydata_free ((mcpc_anydata_t *) prmpt);
}

mcpc_errcode_t
mcpc_prmpt_getref_name (const mcpc_prmpt_t *prmpt, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_meta1 (prmpt, ret, ret_len);
}

mcpc_errcode_t
mcpc_prmpt_getref_desc (const mcpc_prmpt_t *prmpt, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_meta2 (prmpt, ret, ret_len);
}

mcpc_errcode_t
mcpc_prmpt_get_callcb (const mcpc_prmpt_t *prmpt, mcpc_prmpt_callcb_t *ret)
{
  return mcpc_anydata_get_func (prmpt, ret);
}

mcpc_errcode_t
mcpc_prmpt_set_callcb (mcpc_prmpt_t *prmpt, mcpc_prmpt_callcb_t cb)
{
  mcpc_anydata_set_func (prmpt, cb);
  return MCPC_EC_0;
}

MCPC_API mcpc_errcode_t
mcpc_prmpt_addfre_prmptarg (mcpc_prmpt_t *prmpt, mcpc_prmptarg_t *prmptarg)
{
  mcpc_anydata_add_child (prmpt, prmptarg);
  return MCPC_EC_0;

}

MCPC_API void
mcpc_prmpt_addcpy_prmptarg (mcpc_prmpt_t *prmpt, mcpc_prmptarg_t *prmptarg)
{
  mcpc_anydata_addcpy_child (prmpt, prmptarg);	// TODO return EC
}

MCPC_API const mcpc_prmptarg_t *
mcpc_prmpt_get_prmptarg (const mcpc_prmpt_t *prmpt, size_t idx)
{
  return mcpc_anydata_get_child (prmpt, idx);
}

MCPC_API size_t
mcpc_prmpt_get_prmptarg_len (const mcpc_prmpt_t *prmpt)
{
  bug_if_nullptr (prmpt);
  mcpc_anydata_t *prmpt_imp = (mcpc_anydata_t *) prmpt;
  if (prmpt_imp->chd_pool == nullptr)
    return 0;
  return prmpt_imp->chd_pool->len;
}

MCPC_API const mcpc_prmptarg_t *
mcpc_prmpt_get_next_prmptarg (const mcpc_prmpt_t *prmpt)
{
  bug_if_nullptr (prmpt);

  static size_t idx = 0;

  const mcpc_anypool_t *pool = prmpt->chd_pool;
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

MCPC_API const mcpc_prmptarg_t *
mcpc_prmpt_getbyname_prmptarg (const mcpc_prmpt_t *prmpt, const char8_t *parg_name, size_t parg_name_len)
{
  const mcpc_anydata_t *chd = mcpc_anypool_getbymeta1 (prmpt->chd_pool, parg_name, parg_name_len);
  return (mcpc_prmptarg_t *) chd;
}

MCPC_API const mcpc_prmptarg_t *
mcpc_prmpt_getbynament_prmptarg (const mcpc_prmpt_t *prmpt, const char8_t *parg_nament)
{
  const mcpc_anydata_t *chd = mcpc_anypool_getbymeta1nt (prmpt->chd_pool, parg_nament);
  return (mcpc_prmptarg_t *) chd;
}

/* = = = = = = = = = = = = = = = prmptpool = = = = = = = = = = = = = = = */

mcpc_prmptpool_t *
mcpc_prmptpool_new ()
{
  return mcpc_anypool_new ();
}

void
mcpc_prmptpool_free (mcpc_prmptpool_t *prmptpool)
{
  mcpc_anypool_free (prmptpool);
}

void
mcpc_prmptpool_addcpy (mcpc_prmptpool_t *prmptpool, const mcpc_prmpt_t *prmpt)
{
  mcpc_anypool_addcpy (prmptpool, prmpt);
}

void
mcpc_prmptpool_addfre (mcpc_prmptpool_t *prmptpool, mcpc_prmpt_t *prmpt)
{
  mcpc_anypool_addfre (prmptpool, prmpt);
}

size_t
mcpc_prmptpool_get_len (const mcpc_prmptpool_t *prmptpool)
{
  bug_if_nullptr (prmptpool);
  size_t ret = 0;
  ret = ((const mcpc_anypool_t *) prmptpool)->len;
  return ret;
}

const mcpc_prmpt_t *
mcpc_prmptpool_get (const mcpc_prmptpool_t *prmptpool, size_t idx)
{
  return mcpc_anypool_get (prmptpool, idx);
}

const mcpc_prmpt_t *
mcpc_prmptpool_getbyname (const mcpc_prmptpool_t *prmptpool, const char8_t *name, size_t name_len)
{
  return mcpc_anypool_getbymeta1 (prmptpool, name, name_len);
}

/* -= = = = = = = = = = = = = = prmptarghint = = = = = = = = = = = = = = = */

mcpc_prmptarghint_t *
mcpc_prmptarghint_new ()
{
  mcpc_anydata_t *anydata = mcpc_anydata_new_typ (MCPC_U8STR);
  anydata->flags |= ANYDATA_FL_PRMPTARGHINT;
  return anydata;
}

mcpc_prmptarghint_t *
mcpc_prmptarghint_new_vprintf8 (const char8_t *fmt, va_list *vargs)
{
  char8_t *sbuf = mcpc_alloc (1024);
  int printed = vsprintf ((char *) sbuf, (const char *) fmt, *vargs);

  mcpc_prmptarghint_t *prmptarghint = mcpc_prmptarghint_new ();
  bug_if_nz (mcpc_anydata_set_u8str (prmptarghint, sbuf, (size_t) printed));

  free (sbuf);
  return prmptarghint;
}

MCPC_API mcpc_errcode_t
mcpc_prmptarg_add_hint_printf8 (mcpc_prmptarg_t *prmptarg, const char8_t *fmt, ...)
{
  va_list vargs;
  va_start (vargs, fmt);

  mcpc_prmptarghint_t *hint = mcpc_prmptarghint_new_vprintf8 (fmt, &vargs);

  if (prmptarg->chd_pool == nullptr)
    prmptarg->chd_pool = mcpc_anypool_new ();

  mcpc_anypool_addfre (prmptarg->chd_pool, hint);

  va_end (vargs);
  return MCPC_EC_0;
}

mcpc_errcode_t
mcpc_prmptarghint_getref_u8str (const mcpc_prmptarg_t *prmptarghint, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_u8str (prmptarghint, ret, ret_len);
}

const mcpc_prmptarghint_t *
mcpc_prmptarg_get_next_prmptarghint (const mcpc_prmptarg_t *prmptarg)
{
  bug_if_nullptr (prmptarg);

  static size_t idx = 0;

  const mcpc_anypool_t *pool = prmptarg->chd_pool;
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
