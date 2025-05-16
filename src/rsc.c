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

#include "rsc.h"

#include <stdint.h>
#include <stdlib.h>

#include "ext_string.h"

#include "errcode.h"
#include "alloc.h"
#include "anydata.h"

MCPC_API mcpc_rsc_t *
mcpc_rsc_new (const char8_t *uri, const size_t uri_len, const char8_t *name, const size_t name_len)
{
  mcpc_anydata_t *anydata = mcpc_anydata_new_typ_meta1 (MCPC_U8STR, name, name_len);

  anydata->flags |= ANYDATA_FL_RSC;
  anydata->data_mime = MCPC_MIME_TEXT_PLAIN;

  if (MCPC_EC_0 != mcpc_anydata_set_u8str (anydata, uri, uri_len))
    goto badret;

  return (mcpc_rsc_t *) anydata;

badret:
  mcpc_anydata_free (anydata);
  return nullptr;
}

MCPC_API mcpc_rsc_t *
mcpc_rsc_new2 (const char8_t *uri_nt, const char8_t *nament)
{
  return mcpc_rsc_new (uri_nt, u8strlen (uri_nt), nament, u8strlen (nament));
}


MCPC_API mcpc_rsc_t *
mcpc_rsc_new3 (mcpc_mime_t mime, const char8_t *uri_nt, const char8_t *nament)
{
  mcpc_rsc_t *rsc = mcpc_rsc_new2 (uri_nt, nament);
  rsc->data_mime = mime;
  return rsc;
}

MCPC_API mcpc_errcode_t
mcpc_rsc_get_uri (const mcpc_rsc_t *rsc, char8_t *ret, size_t ret_cap, size_t *ret_len)
{
  return mcpc_anydata_get_u8str (rsc, ret, ret_cap, ret_len);
}

MCPC_API mcpc_errcode_t
mcpc_rsc_getref_uri (const mcpc_rsc_t *rsc, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_u8str (rsc, ret, ret_len);
}

MCPC_API mcpc_errcode_t
mcpc_rsc_getref_name (const mcpc_rsc_t *rsc, const char8_t **ret, size_t *ret_len)
{
  return mcpc_anydata_getref_meta1 (rsc, ret, ret_len);
}

MCPC_API mcpc_errcode_t
mcpc_rsc_get_mime (const mcpc_rsc_t *rsc, mcpc_mime_t *ret)
{
  bug_if_nullptr (rsc);
  bug_if_nullptr (ret);
  *ret = rsc->data_mime;
  return MCPC_EC_0;
}

MCPC_API void
mcpc_rsc_set_mime (mcpc_rsc_t *rsc, mcpc_mime_t mime)
{
  bug_if_nullptr (rsc);
  rsc->data_mime = mime;
}

MCPC_API void
mcpc_rsc_free (mcpc_rsc_t *rsc)
{
  mcpc_anydata_free (rsc);
}

// --------------------------- rscpool ---------------------------

mcpc_rscpool_t *
mcpc_rscpool_new ()
{
  return mcpc_anypool_new ();
}

void
mcpc_rscpool_free (mcpc_rscpool_t *rscpool)
{
  mcpc_anypool_free (rscpool);
}

void
mcpc_rscpool_addcpy (mcpc_rscpool_t *rscpool, const mcpc_rsc_t *rsc)
{
  mcpc_anypool_addcpy (rscpool, rsc);
}

void
mcpc_rscpool_addfre (mcpc_rscpool_t *rscpool, mcpc_rsc_t *rsc)
{
  mcpc_anypool_addfre (rscpool, rsc);
}

size_t
mcpc_rscpool_get_len (const mcpc_rscpool_t *rscpool)
{
  bug_if_nullptr (rscpool);
  size_t ret = 0;
  ret = ((const mcpc_anypool_t *) rscpool)->len;
  return ret;
}

const mcpc_rsc_t *
mcpc_rscpool_get (const mcpc_rscpool_t *rscpool, size_t idx)
{
  return mcpc_anypool_get (rscpool, idx);
}

const mcpc_rsc_t *
mcpc_rscpool_getbyname (const mcpc_rscpool_t *rscpool, const char8_t *name, size_t name_len)
{
  return mcpc_anypool_getbymeta1 (rscpool, name, name_len);
}

const mcpc_rsc_t *
mcpc_rscpool_get_next (const mcpc_rscpool_t *rscpool)
{
  bug_if_nullptr (rscpool);

  static size_t idx = 0;

  const mcpc_anypool_t *pool = rscpool;
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
