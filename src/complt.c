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

#include "complt.h"

#include "anydata.h"
#include "ext_string.h"


mcpc_complt_t *
mcpc_complt_new ()
{
  mcpc_anydata_t *hp = mcpc_anydata_new ();

  hp->flags |= ANYDATA_FL_COMPLT;

  return hp;
}

mcpc_errcode_t
mcpc_complt_add_compltcandi_u8str (mcpc_complt_t *complt, const char8_t *u8str, size_t u8str_len)
{
  bug_if_nullptr (complt);
  bug_if_nullptr (u8str);
  mcpc_anydata_t *chd = mcpc_anydata_new ();
  bug_if_nz (mcpc_anydata_set_u8str (chd, u8str, u8str_len));
  if (complt->chd_pool == nullptr)
    complt->chd_pool = mcpc_anypool_new ();
  (mcpc_anypool_addfre (complt->chd_pool, chd));
  return MCPC_EC_0;
}

// provide completions for specific prompt arg, completing its hint, (currently hint is anydata with merely u8str data)
mcpc_complt_t *
mcpc_complt_new_prmptarg (const mcpc_prmpt_t *prmpt, const char8_t *argname, size_t argname_len, const char8_t *argval,
			  size_t argval_len)
{
  mcpc_complt_t *complt = mcpc_complt_new ();

  const mcpc_prmptarg_t *prmptarg = mcpc_prmpt_getbyname_prmptarg (prmpt, argname, argname_len);
  if (prmptarg == nullptr)
    return complt;

  bool match_any = argval_len == 0;

  const mcpc_prmptarghint_t *cur_candi = nullptr;
  while ((cur_candi = mcpc_prmptarg_get_next_prmptarghint (prmptarg)))
    {
      const char8_t *cur_val;
      size_t cur_val_len;
      bug_if_nz (mcpc_prmptarghint_getref_u8str (cur_candi, &cur_val, &cur_val_len));

      if (match_any)
	bug_if_nz (mcpc_complt_add_compltcandi_u8str (complt, cur_val, cur_val_len));
      else
	{
	  size_t cmpsz = min_size (cur_val_len, argval_len);
	  if (0 == u8strncmp (argval, cur_val, cmpsz))
	    {
	      bug_if_nz (mcpc_complt_add_compltcandi_u8str (complt, cur_val, cur_val_len));
	    }
	}
    }

  return complt;
}

// provide completions for specific rsc, completing uri
mcpc_complt_t *
mcpc_complt_new_rsc (const mcpc_rscpool_t *rscpool, const char8_t *uriparts, size_t uriparts_len)
{
  mcpc_complt_t *complt = mcpc_complt_new ();

  bool match_any = uriparts_len == 0;

  const mcpc_rsc_t *cur_rsc = nullptr;
  while ((cur_rsc = mcpc_rscpool_get_next (rscpool)))
    {
      const char8_t *cur_uri;
      size_t cur_uri_len;
      bug_if_nz (mcpc_rsc_getref_uri (cur_rsc, &cur_uri, &cur_uri_len));

      if (match_any)
	bug_if_nz (mcpc_complt_add_compltcandi_u8str (complt, cur_uri, cur_uri_len));
      else if (uriparts_len <= cur_uri_len)
	{
	  size_t cmpsz = uriparts_len;
	  if (0 == u8strncmp (cur_uri, uriparts, cmpsz))
	    bug_if_nz (mcpc_complt_add_compltcandi_u8str (complt, cur_uri, cur_uri_len));
	}
    }

  return complt;
}

void
mcpc_complt_free (mcpc_complt_t *complt)
{
  mcpc_anydata_free (complt);
}

mcpc_errcode_t
mcpc_complt_get_compltcandi_len (const mcpc_complt_t *complt, size_t *ret)
{
  bug_if_nullptr (complt);
  if (complt->chd_pool == nullptr)
    *ret = 0;
  else
    *ret = complt->chd_pool->len;
  return MCPC_EC_0;
}

const mcpc_compltcand_t *
mcpc_complt_get_next_compltcand (const mcpc_complt_t *complt)
{
  bug_if_nullptr (complt);

  static size_t idx = 0;

  const mcpc_anypool_t *pool = complt->chd_pool;
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

mcpc_errcode_t
mcpc_compltcand_getref_u8str (const mcpc_compltcand_t *compltcand, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_u8str (compltcand, ret, ret_len);
}
