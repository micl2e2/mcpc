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

#include "ucbr.h"

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>

#include "alloc.h"
#include "anydata.h"
#include "errcode.h"
#include "ext_string.h"

/* = = = = = = = = = = = = = = = = ucbrchd = = = = = = = = = = = = = = = = */

mcpc_ucbrchd_t *
mcpc_ucbrchd_new_vprintf8 (const char8_t *fmt, va_list *vargs)
{
  size_t sbuf_cap = 1024;
  size_t sbuf_len = 0;
  char8_t *sbuf = mcpc_alloc (sbuf_cap);
  int printed = 0;
  while (true)
    {
      va_list vargs_cp;
      va_copy (vargs_cp, *vargs);
      printed
          = vsnprintf ((char *)sbuf, sbuf_cap, (const char *)fmt, vargs_cp);
      bug_if (printed < 0);
      if ((size_t)printed >= sbuf_cap)
        {
          sbuf_cap += sbuf_cap;
          sbuf = mcpc_realloc (sbuf, sbuf_cap);
        }
      else
        {
          sbuf_len = (size_t)printed;
          break;
        }
    }

  mcpc_anydata_t *anydata = mcpc_anydata_new_typ (MCPC_U8STR);

  if (MCPC_EC_0 != mcpc_anydata_set_u8str (anydata, sbuf, sbuf_len))
    goto badret;

  free (sbuf);
  return (mcpc_ucbrchd_t *)anydata;

badret:
  free (sbuf);
  mcpc_anydata_free (anydata);
  return nullptr;
}

mcpc_errcode_t
mcpc_ucbrchd_getref_u8str (const mcpc_ucbrchd_t *ucbrchd, const char8_t **ret,
                           size_t *ret_len)
{
  return mcpc_anydata_getref_u8str (ucbrchd, ret, ret_len);
}

mcpc_errcode_t
mcpc_ucbrchd_get_data_type (const mcpc_ucbrchd_t *ucbrchd, mcpc_anytype_t *ret)
{
  bug_if_nullptr (ucbrchd);
  bug_if_nullptr (ret);

  *ret = ucbrchd->data_typ;

  return MCPC_EC_0;
}

bool
mcpc_ucbrchd_is_tool_callres (const mcpc_ucbrchd_t *ucbrchd)
{
  return ucbrchd->flags & ANYDATA_FL_USRCBRES_TOOLCALL;
}

bool
mcpc_ucbrchd_is_prmpt_callres (const mcpc_ucbrchd_t *ucbrchd)
{
  return ucbrchd->flags & ANYDATA_FL_USRCBRES_PRMPTCALL;
}

bool
mcpc_ucbrchd_is_assist_prmpt (const mcpc_ucbrchd_t *ucbrchd)
{
  return ucbrchd->flags & ANYDATA_FL_USRCBRES_PRMPTCALL_ASSIST;
}

/* = = = = = = = = = = = = = = = = = ucbr = = = = = = = = = = = = = = = = = */

mcpc_ucbr_t *
mcpc_ucbr_new ()
{
  return mcpc_anypool_new ();
}

void
mcpc_ucbr_free (mcpc_ucbr_t *ucbr)
{
  mcpc_anypool_free (ucbr);
}

void
mcpc_ucbr_addcpy (mcpc_ucbr_t *ucbr, const mcpc_ucbrchd_t *ucbrchd)
{
  mcpc_anypool_addcpy (ucbr, ucbrchd);
}

void
mcpc_ucbr_addfre (mcpc_ucbr_t *ucbr, mcpc_ucbrchd_t *ucbrchd)
{
  mcpc_anypool_addfre (ucbr, ucbrchd);
}

bool
mcpc_ucbr_is_err (const mcpc_ucbr_t *ucbr)
{
  bug_if_nullptr (ucbr);
  return ucbr->flags & ANYPOOL_FL_USRCBRES_TOOLCALL_ERROR;
}

size_t
mcpc_ucbr_get_len (const mcpc_ucbr_t *ucbr)
{
  bug_if_nullptr (ucbr);
  size_t ret = 0;
  ret = ((const mcpc_anypool_t *)ucbr)->len;
  return ret;
}

const mcpc_ucbrchd_t *
mcpc_ucbr_get (const mcpc_ucbr_t *ucbr, size_t idx)
{
  return mcpc_anypool_get (ucbr, idx);
}

const mcpc_ucbrchd_t *
mcpc_ucbr_getbyname (const mcpc_ucbr_t *ucbr, const char8_t *name,
                     size_t name_len)
{
  return mcpc_anypool_getbymeta1 (ucbr, name, name_len);
}

const mcpc_ucbrchd_t *
mcpc_ucbr_get_next (const mcpc_ucbr_t *ucbr)
{
  bug_if_nullptr (ucbr);

  static size_t idx = 0;

  const mcpc_anypool_t *pool = ucbr;
  if (pool == nullptr)
    return nullptr;

  const size_t pool_len = pool->len;
  if (pool_len == 0)
    return nullptr;

  if (idx == pool_len) // TODO  MT-SAFE
    {
      idx = 0;
      return nullptr;
    }

  const mcpc_anydata_t *ret = pool->head + idx;
  idx += 1;

  return ret;
}

size_t
mcpc_ucbr_get_serlz_lenhint (const mcpc_ucbr_t *ucbr)
{
  bug_if_nullptr (ucbr);
  size_t ret = 0;

  const mcpc_ucbrchd_t *cur_chd = nullptr;
  while ((cur_chd = mcpc_ucbr_get_next (ucbr)))
    {
      ret += cur_chd->data_len;
    }

  const size_t tshold = 1024;
  size_t extra = 0;

  if (ret * 1 / 2 < tshold)
    extra = tshold;
  else
    extra = (ret * 1 / 2); // TODO find a optimal one

  ret += extra;

  return ret;
}

void
mcpc_ucbr_toolcallres_add_text_vprintf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt,
                                         va_list *vargs)
{
  bug_if_nullptr (ucbr);
  bug_if_nullptr (fmt);
  bug_if_nullptr (vargs);

  ucbr->flags |= ANYPOOL_FL_USRCBRES_TOOLCALL;

  mcpc_ucbrchd_t *newctn = mcpc_ucbrchd_new_vprintf8 (fmt, vargs);
  newctn->flags |= ANYDATA_FL_USRCBRES_TOOLCALL;
  newctn->flags |= ANYDATA_FL_USRCBRES_TOOLCALL_TXTCTN;
  mcpc_ucbr_addfre (ucbr, newctn);
}

MCPC_API void
mcpc_ucbr_toolcall_add_text_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt,
                                     ...)
{
  va_list vargs;
  va_start (vargs, fmt);

  mcpc_ucbr_toolcallres_add_text_vprintf8 (ucbr, fmt, &vargs);

  va_end (vargs);
}

MCPC_API void
mcpc_ucbr_toolcall_add_errmsg_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt,
                                       ...)
{
  va_list vargs;
  va_start (vargs, fmt);

  ucbr->flags |= ANYPOOL_FL_USRCBRES_TOOLCALL_ERROR;
  mcpc_ucbr_toolcallres_add_text_vprintf8 (ucbr, fmt, &vargs);

  va_end (vargs);
}

MCPC_API void
mcpc_ucbr_prmptget_add_user_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt,
                                     ...)
{
  va_list vargs;
  va_start (vargs, fmt);

  ucbr->flags |= ANYPOOL_FL_USRCBRES_PRMPTCALL;

  mcpc_ucbrchd_t *newctn = mcpc_ucbrchd_new_vprintf8 (fmt, &vargs);
  newctn->flags |= ANYDATA_FL_USRCBRES_PRMPTCALL;

  mcpc_ucbr_addfre (ucbr, newctn);

  va_end (vargs);
}

MCPC_API void
mcpc_ucbr_prmptget_add_assist_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt,
                                       ...)
{
  va_list vargs;
  va_start (vargs, fmt);

  ucbr->flags |= ANYPOOL_FL_USRCBRES_PRMPTCALL;

  mcpc_ucbrchd_t *newctn = mcpc_ucbrchd_new_vprintf8 (fmt, &vargs);
  newctn->flags |= ANYDATA_FL_USRCBRES_PRMPTCALL;
  newctn->flags |= ANYDATA_FL_USRCBRES_PRMPTCALL_ASSIST;

  mcpc_ucbr_addfre (ucbr, newctn);

  va_end (vargs);
}
