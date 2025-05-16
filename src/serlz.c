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

#define __TU__ "serlz"

#include "serlz.h"

#include "ext_string.h"
#include "log.h"



// ------------------------------ tool ------------------------------

u8_t
serlz_tool_inputschema_properties_prop (retbuf_t rtbf, const mcpc_toolprop_t *tprop)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  const char8_t *name, *desc = nullptr;
  size_t name_len, desc_len = 0;

  bug_if_nz (mcpc_toolprop_getref_name (tprop, &name, &name_len));
  bug_if_nz (mcpc_toolprop_getref_desc (tprop, &desc, &desc_len));

  mcpc_anytype_t typ = MCPC_NONE;
  bug_if_nz (mcpc_toolprop_get_data_type (tprop, &typ));

  if (false)
    ;
  else if (mcpc_anytype_is_intlike (typ))
    {
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%Q"), "type", "number");
    }
  else if (typ == MCPC_U8STR)
    {
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%Q"), "type", "string");
    }
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "title", name_len, name);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "description", desc_len, desc);

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

u8_t
serlz_tool_inputschema_properties (retbuf_t rtbf, const mcpc_toolproppool_t *tppool)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  if (tppool != nullptr)
    {
      size_t len_tppool = mcpc_toolproppool_get_len (tppool);
      if (len_tppool > 0)
	{
	  for (size_t i = 0; i < len_tppool; i++)
	    {
	      const mcpc_toolprop_t *tprop = mcpc_toolproppool_get (tppool, i);
	      size_t name_len = 0;
	      const char8_t *name = nullptr;
	      bug_if (mcpc_toolprop_getref_name (tprop, &name, &name_len));

	      rtbuf_printf_mjfmt (rtbf, u8c1 ("%.*Q:"), name_len, name);
	      serlz_tool_inputschema_properties_prop (rtbf, tprop);
	      if (i != len_tppool - 1)
		rtbuf_printf_mjfmt (rtbf, u8c1 (","));
	    }
	}
    }


  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

u8_t
serlz_tool_inputschema (retbuf_t rtbf, const mcpc_tool_t *tool)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%Q"), "type", "object");
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "properties");
  serlz_tool_inputschema_properties (rtbf, mcpc_tool_get_toolproppool (tool));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

uint8_t
serlz_tool (retbuf_t rtbf, const mcpc_tool_t *tool)
{
  const char8_t *name, *desc = nullptr;
  size_t name_len, desc_len = 0;
  bug_if_nz (mcpc_toolprop_getref_name (tool, &name, &name_len));
  bug_if_nz (mcpc_toolprop_getref_desc (tool, &desc, &desc_len));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "name", name_len, name);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "description", desc_len, desc);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "inputSchema");
  serlz_tool_inputschema (rtbf, tool);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

u8_t
serlz_toolpool (retbuf_t rtbf, const mcpc_toolpool_t *toolpool)
{
  size_t len_tpool = mcpc_toolpool_get_len (toolpool);

  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "tools");
  rtbuf_printf_mjfmt (rtbf, u8c1 ("["));

  // TODO TODO TODO use iterator
  if (toolpool != nullptr && len_tpool > 0)
    {
      for (size_t i = 0; i < len_tpool; i++)
	{
	  const mcpc_tool_t *cur_tool = mcpc_toolpool_get (toolpool, i);
	  serlz_tool (rtbf, cur_tool);
	  if (i != len_tpool - 1)
	    rtbuf_printf_mjfmt (rtbf, u8c1 (","));
	}
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("]"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

// ----------------------------- prmpt -----------------------------



u8_t
serlz_prmptarg (retbuf_t rtbf, const mcpc_prmptarg_t *prmptarg)
{
  const char8_t *name, *desc = nullptr;
  size_t name_len, desc_len = 0;
  bool required = false;

  bug_if_nz (mcpc_prmptarg_getref_name (prmptarg, &name, &name_len));
  bug_if_nz (mcpc_prmptarg_getref_desc (prmptarg, &desc, &desc_len));
  required = mcpc_prmptarg_is_required (prmptarg);

  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "name", name_len, name);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "description", desc_len, desc);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%B"), "required", required);

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}


uint8_t
serlz_prmpt (retbuf_t rtbf, const mcpc_prmpt_t *prmpt)
{
  const char8_t *name, *desc = nullptr;
  size_t name_len, desc_len = 0;
  bug_if_nz (mcpc_prmptarg_getref_name (prmpt, &name, &name_len));
  bug_if_nz (mcpc_prmptarg_getref_desc (prmpt, &desc, &desc_len));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "name", name_len, name);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "description", desc_len, desc);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "arguments");

  rtbuf_printf_mjfmt (rtbf, u8c1 ("["));

  const mcpc_prmptarg_t *cur_prmptarg = nullptr;
  bool first = true;
  while ((cur_prmptarg = mcpc_prmpt_get_next_prmptarg (prmpt)))
    {
      if (!first)
	rtbuf_printf_mjfmt (rtbf, u8c1 (","));
      serlz_prmptarg (rtbf, cur_prmptarg);
      first = false;
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("]"));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

u8_t
serlz_prmptpool (retbuf_t rtbf, const mcpc_prmptpool_t *prmptpool)
{
  size_t len_tpool = mcpc_prmptpool_get_len (prmptpool);

  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "prompts");
  rtbuf_printf_mjfmt (rtbf, u8c1 ("["));

  if (prmptpool != nullptr && len_tpool > 0)
    {
      for (size_t i = 0; i < len_tpool; i++)
	{
	  const mcpc_prmpt_t *cur_prmpt = mcpc_prmptpool_get (prmptpool, i);
	  serlz_prmpt (rtbf, cur_prmpt);
	  if (i != len_tpool - 1)
	    rtbuf_printf_mjfmt (rtbf, u8c1 (","));
	}
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("]"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}


/* ------------------------------ rsc ------------------------------ */

u8_t
serlz_rsc (retbuf_t rtbf, const mcpc_rsc_t *rsc)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  const char8_t *ref_uri = nullptr;
  size_t ref_uri_len = 0;
  const char8_t *ref_name = nullptr;
  size_t ref_name_len = 0;
  mcpc_mime_t mime = MCPC_MIME_NONE;

  mcpc_rsc_getref_uri (rsc, &ref_uri, &ref_uri_len);
  mcpc_rsc_getref_name (rsc, &ref_name, &ref_name_len);
  mcpc_rsc_get_mime (rsc, &mime);

  bool serlz_uri = ref_uri_len > 0 && ref_uri != nullptr;
  bool serlz_name = ref_name_len > 0 && ref_name != nullptr;
  bool serlz_mime = mime != MCPC_MIME_NONE;

  // uri is ID, hence first
  if (serlz_uri)
    {
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "uri", ref_uri_len, (const char *) ref_uri);
    }

  if (serlz_name)
    {
      if (serlz_uri)
	rtbuf_printf_mjfmt (rtbf, u8c1 (","));
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "name", ref_name_len, ref_name);
    }

  if (serlz_mime)
    {
      if (serlz_name || serlz_uri)
	rtbuf_printf_mjfmt (rtbf, u8c1 (","));
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "mimeType");
      if (false);
      else if (mime == MCPC_MIME_TEXT_PLAIN)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("text/plain"));
      else if (mime == MCPC_MIME_IMAGE_PNG)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("image/png"));
      else if (mime == MCPC_MIME_IMAGE_JPEG)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("image/jpeg"));
      else if (mime == MCPC_MIME_IMAGE_GIF)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("image/gif"));
      else if (mime == MCPC_MIME_AUDIO_MPEG)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("audio/mpeg"));
      else if (mime == MCPC_MIME_AUDIO_WAV)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("audio/wav"));
      else if (mime == MCPC_MIME_VIDEO_MPEG)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("video/mpeg"));
      else if (mime == MCPC_MIME_VIDEO_AVI)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("video/avi"));
      else if (mime == MCPC_MIME_APPLI_OCTS)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("application/octet-stream"));
      else if (mime == MCPC_MIME_APPLI_JSON)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("application/json"));
      else if (mime == MCPC_MIME_APPLI_PDF)
	rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), u8c1 ("application/pdf"));
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));

  return 0;
}

u8_t
serlz_rscpool (retbuf_t rtbf, const mcpc_rscpool_t *rscpool)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "resources");
  rtbuf_printf_mjfmt (rtbf, u8c1 ("["));


  const mcpc_rsc_t *cur_rsc = nullptr;
  bool first = true;
  while ((cur_rsc = mcpc_rscpool_get_next (rscpool)))
    {
      if (!first)
	rtbuf_printf_mjfmt (rtbf, u8c1 (","));
      serlz_rsc (rtbf, cur_rsc);
      first = false;
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("]"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

/* ------------------------------- - ------------------------------- */

uint8_t
serlz_serverInfo (retbuf_t rtbf, const mcpc_server_t *sv)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "name", sv->name_len, sv->name);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%.*Q"), "version", sv->ver_len, sv->ver);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

uint8_t
serlz_capasprompts (retbuf_t rtbf, const mcpc_server_t *sv)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "listChanged");
  bool supp_lschg = mcpc_server_supp_prompts_lschg (sv);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%B"), supp_lschg);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

uint8_t
serlz_capastools (retbuf_t rtbf, const mcpc_server_t *sv)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "listChanged");
  bool supp_lschg = mcpc_server_supp_tools_lschg (sv);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%B"), supp_lschg);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

uint8_t
serlz_capasresources (retbuf_t rtbf, const mcpc_server_t *sv)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "subscribe");
  bool supp_subs = mcpc_server_supp_rscs_subs (sv);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%B"), supp_subs);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "listChanged");
  bool supp_lschg = mcpc_server_supp_rscs_lschg (sv);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%B"), supp_lschg);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

uint8_t
serlz_capas (retbuf_t rtbf, const mcpc_server_t *sv)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  if (mcpc_server_supp_prompts (sv))
    {
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "prompts");
      serlz_capasprompts (rtbf, sv);
      rtbuf_printf_mjfmt (rtbf, u8c1 (","));
    }

  if (mcpc_server_supp_tools (sv))
    {
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "tools");
      serlz_capastools (rtbf, sv);
      rtbuf_printf_mjfmt (rtbf, u8c1 (","));
    }

  if (mcpc_server_supp_rscs (sv))
    {
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "resources");
      serlz_capasresources (rtbf, sv);
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

uint8_t
serlz_initres (retbuf_t rtbf, const mcpc_server_t *sv)
{
  rtbuf_printf (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%Q"), "protocolVersion", "2024-11-05");
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "serverInfo");
  serlz_serverInfo (rtbf, sv);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "capabilities");
  serlz_capas (rtbf, sv);
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

// ------------------------------ ucbr ------------------------------

uint8_t
serlz_ucbrchd_tool_callres (retbuf_t rtbf, const mcpc_ucbrchd_t *ucbrchd)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%Q"), "type", "text");
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "text");

  mcpc_anytype_t data_type = MCPC_NONE;
  bug_if_nz (mcpc_ucbrchd_get_data_type (ucbrchd, &data_type));

  if (false)
    ;
  else if (data_type == MCPC_U8STR)
    {
      const char8_t *s = nullptr;
      size_t s_len = 0;
      mcpc_ucbrchd_getref_u8str (ucbrchd, &s, &s_len);
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%.*Q"), s_len, (const char *) s);
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

uint8_t
serlz_ucbrchd_prmpt_callres (retbuf_t rtbf, const mcpc_ucbrchd_t *ucbrchd)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "role");
  if (mcpc_ucbrchd_is_assist_prmpt (ucbrchd))
    rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), "assistant");
  else
    rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q"), "user");
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "content");
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%Q"), "type", "text");
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "text");

  mcpc_anytype_t data_type = MCPC_NONE;
  bug_if_nz (mcpc_ucbrchd_get_data_type (ucbrchd, &data_type));

  if (false)
    ;
  else if (data_type == MCPC_U8STR)
    {
      const char8_t *s = nullptr;
      size_t s_len = 0;
      mcpc_ucbrchd_getref_u8str (ucbrchd, &s, &s_len);
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%.*Q"), s_len, (const char *) s);
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

uint8_t
serlz_ucbrchd (retbuf_t rtbf, const mcpc_ucbrchd_t *ucbrchd)
{
  if (false);
  else if (mcpc_ucbrchd_is_tool_callres (ucbrchd))
    {
      return serlz_ucbrchd_tool_callres (rtbf, ucbrchd);
    }
  else if (mcpc_ucbrchd_is_prmpt_callres (ucbrchd))
    {
      return serlz_ucbrchd_prmpt_callres (rtbf, ucbrchd);
    }
  return 0;
}

u8_t
serlz_ucbr (retbuf_t rtbf, const mcpc_ucbr_t *ucbr)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("["));

  const mcpc_ucbrchd_t *cur_ucbrchd = nullptr;
  bool first = true;
  while ((cur_ucbrchd = mcpc_ucbr_get_next (ucbr)))
    {
      if (!first)
	rtbuf_printf_mjfmt (rtbf, u8c1 (","));
      serlz_ucbrchd (rtbf, cur_ucbrchd);
      first = false;
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("]"));
  return 0;
}

u8_t
serlz_tool_callres (retbuf_t rtbf, const mcpc_ucbr_t *ucbr)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  if (mcpc_ucbr_is_err (ucbr))
    {
      // https://modelcontextprotocol.io/docs/concepts/tools#error-handling-2
      rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%B"), "isError", true);
      rtbuf_printf_mjfmt (rtbf, u8c1 (","));
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "content");
  serlz_ucbr (rtbf, ucbr);

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}

u8_t
serlz_prmpt_callres (retbuf_t rtbf, const mcpc_ucbr_t *ucbr)
{
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%Q"), "description", "Prompt List");
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "messages");
  serlz_ucbr (rtbf, ucbr);

  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}


// ----------------------------- complt -----------------------------

u8_t
serlz_complt (retbuf_t rtbf, const mcpc_complt_t *complt)
{
  size_t total = 0;

  mcpc_complt_get_compltcandi_len (complt, &total);

  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "completion");
  rtbuf_printf_mjfmt (rtbf, u8c1 ("{"));

  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%lu"), "total", total);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:%B"), "hasMore", false);
  rtbuf_printf_mjfmt (rtbf, u8c1 (","));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("%Q:"), "values");
  rtbuf_printf_mjfmt (rtbf, u8c1 ("["));

  const mcpc_compltcand_t *cur_compltcand = nullptr;
  bool first = true;
  while ((cur_compltcand = mcpc_complt_get_next_compltcand (complt)))
    // LASTEDIT   0507
    {
      if (!first)
	rtbuf_printf_mjfmt (rtbf, u8c1 (","));
      const char8_t *sbuf = nullptr;
      size_t sbuf_len = 0;
      bug_if_nz (mcpc_compltcand_getref_u8str (cur_compltcand, &sbuf, &sbuf_len));	// NOT IMPL, IMPL@0508
      bug_if_nullptr (sbuf);
      bug_if_zero (sbuf_len);

      rtbuf_printf_mjfmt (rtbf, u8c1 ("%.*Q"), sbuf_len, sbuf);
      first = false;
    }

  rtbuf_printf_mjfmt (rtbf, u8c1 ("]"));


  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  rtbuf_printf_mjfmt (rtbf, u8c1 ("}"));
  return 0;
}
