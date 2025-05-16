
# Table of Contents

-   [Server](#server)
    -   [`mcpc_server_t`](#=mcpc_server_t=)
    -   [`mcpc_server_new_iostrm`](#=mcpc_server_new_iostrm=)
    -   [`mcpc_server_new_tcp`](#=mcpc_server_new_tcp=)
    -   [`mcpc_server_set_nament`](#=mcpc_server_set_nament=)
    -   [`mcpc_server_capa_enable_prmt`](#=mcpc_server_capa_enable_prmt=)
    -   [`mcpc_server_capa_enable_prmt_listchg`](#=mcpc_server_capa_enable_prmt_listchg=)
    -   [`mcpc_server_capa_enable_tool`](#=mcpc_server_capa_enable_tool=)
    -   [`mcpc_server_capa_enable_tool_listchg`](#=mcpc_server_capa_enable_tool_listchg=)
    -   [`mcpc_server_capa_enable_rsc`](#=mcpc_server_capa_enable_rsc=)
    -   [`mcpc_server_capa_enable_rsc_subscr`](#=mcpc_server_capa_enable_rsc_subscr=)
    -   [`mcpc_server_capa_enable_rsc_listchg`](#=mcpc_server_capa_enable_rsc_listchg=)
    -   [`mcpc_server_capa_enable_complt`](#=mcpc_server_capa_enable_complt=)
    -   [`mcpc_server_add_tool`](#=mcpc_server_add_tool=)
    -   [`mcpc_server_add_prmpt`](#=mcpc_server_add_prmpt=)
    -   [`mcpc_server_add_rsc`](#=mcpc_server_add_rsc=)
    -   [`mcpc_server_start`](#=mcpc_server_start=)
    -   [`mcpc_server_close`](#=mcpc_server_close=)
-   [Tool](#org386a1c2)
    -   [`mcpc_tool_t`](#=mcpc_tool_t=)
    -   [`mcpc_toolprop_t`](#=mcpc_toolprop_t=)
    -   [`mcpc_tcallcb_t`](#=mcpc_tcallcb_t=)
    -   [`mcpc_toolprop_new`](#=mcpc_toolprop_new=)
    -   [`mcpc_toolprop_new2`](#=mcpc_toolprop_new2=)
    -   [`mcpc_tool_new`](#=mcpc_tool_new=)
    -   [`mcpc_tool_new2`](#=mcpc_tool_new2=)
    -   [`mcpc_tool_addfre_toolprop`](#=mcpc_tool_addfre_toolprop=)
    -   [`mcpc_tool_addcpy_toolprop`](#=mcpc_tool_addcpy_toolprop=)
    -   [`mcpc_tool_add_toolprop`](#=mcpc_tool_add_toolprop=)
    -   [`mcpc_tool_get_toolprop` (deprecate)](#=mcpc_tool_get_toolprop=)
    -   [`mcpc_tool_get_toolprop_len`](#=mcpc_tool_get_toolprop_len=)
    -   [`mcpc_tool_get_next_toolprop`](#=mcpc_tool_get_next_toolprop=)
    -   [`mcpc_tool_get_tpropval_i32`](#=mcpc_tool_get_tpropval_i32=)
    -   [`mcpc_tool_get_tpropval_u8str`](#=mcpc_tool_get_tpropval_u8str=)
    -   [`mcpc_tool_get_call_cb`](#=mcpc_tool_get_call_cb=)
    -   [`mcpc_tool_set_call_cb`](#=mcpc_tool_set_call_cb=)
    -   [`mcpc_toolcall_result_add_text_printf8`](#=mcpc_toolcall_result_add_text_printf8=)
    -   [`mcpc_toolcall_result_add_errmsg_printf8`](#=mcpc_toolcall_result_add_errmsg_printf8=)
-   [Resource](#org52ee5a7)
    -   [`mcpc_rsc_t`](#=mcpc_rsc_t=)
    -   [`mcpc_rsc_new`](#=mcpc_rsc_new=)
    -   [`mcpc_rsc_new2`](#=mcpc_rsc_new2=)
    -   [`mcpc_rsc_new3`](#=mcpc_rsc_new3=)
    -   [`mcpc_rsc_free`](#=mcpc_rsc_free=)
    -   [`mcpc_rsc_get_uri`](#=mcpc_rsc_get_uri=)
    -   [`mcpc_rsc_getref_uri`](#=mcpc_rsc_getref_uri=)
    -   [`mcpc_rsc_getref_name`](#=mcpc_rsc_getref_name=)
    -   [`mcpc_rsc_get_mime`](#=mcpc_rsc_get_mime=)
-   [Prompt](#org211140d)
    -   [`mcpc_prmpt_t`](#=mcpc_prmpt_t=)
    -   [`mcpc_prmptarg_t`](#=mcpc_prmptarg_t=)
    -   [`mcpc_prmptarghint_t`](#=mcpc_prmptarghint_t=)
    -   [`mcpc_prmpt_callcb_t`](#=mcpc_prmpt_callcb_t=)
    -   [`mcpc_prmptarg_new`](#=mcpc_prmptarg_new=)
    -   [`mcpc_prmptarg_new2`](#=mcpc_prmptarg_new2=)
    -   [`mcpc_prmptarg_new3`](#=mcpc_prmptarg_new3=)
    -   [`mcpc_prmpt_new`](#=mcpc_prmpt_new=)
    -   [`mcpc_prmpt_new2`](#=mcpc_prmpt_new2=)
    -   [`mcpc_prmpt_new3`](#=mcpc_prmpt_new3=)
    -   [`mcpc_prmpt_addfre_prmptarg`](#=mcpc_prmpt_addfre_prmptarg=)
    -   [`mcpc_prmpt_addcpy_prmptarg`](#=mcpc_prmpt_addcpy_prmptarg=)
    -   [`mcpc_prmpt_add_prmptarg`](#=mcpc_prmpt_add_prmptarg=)
    -   [`mcpc_prmpt_get_prmptarg` (deprecated)](#=mcpc_prmpt_get_prmptarg=)
    -   [`mcpc_prmpt_get_prmptarg_len`](#=mcpc_prmpt_get_prmptarg_len=)
    -   [`mcpc_prmpt_get_next_prmptarg`](#=mcpc_prmpt_get_next_prmptarg=)
    -   [`mcpc_prmpt_getbyname_prmptarg`](#=mcpc_prmpt_getbyname_prmptarg=)
    -   [`mcpc_prmpt_getbynament_prmptarg`](#=mcpc_prmpt_getbynament_prmptarg=)
    -   [`mcpc_prmpt_get_callcb`](#=mcpc_prmpt_get_callcb=)
    -   [`mcpc_prmpt_set_callcb`](#=mcpc_prmpt_set_callcb=)
    -   [`mcpc_prmptarg_get_u8str`](#=mcpc_prmptarg_get_u8str=)
    -   [`mcpc_prmptarg_getref_u8str`](#=mcpc_prmptarg_getref_u8str=)
    -   [`mcpc_prmptarg_add_hint_printf8`](#=mcpc_prmptarg_add_hint_printf8=)
    -   [`mcpc_prmptget_result_add_user_printf8`](#=mcpc_prmptget_result_add_user_printf8=)
    -   [`mcpc_prmptget_result_add_assist_printf8`](#=mcpc_prmptget_result_add_assist_printf8=)
-   [Others](#org6f84d9e)
    -   [`mcpc_errcode_t`](#=mcpc_)
    -   [`mcpc_anytype_t`](#=mcpc_anytype_t=)
    -   [`mcpc_mime_t`](#=mcpc_mime_t=)
    -   [`mcpc_ucbr_t`](#=mcpc_ucbr_t=)
    -   [`mcpc_ucbr_toolcall_add_text_printf8`](#=mcpc_ucbr_toolcall_add_text_printf8=)
    -   [`mcpc_ucbr_toolcall_add_errmsg_printf8`](#=mcpc_ucbr_toolcall_add_errmsg_printf8=)
    -   [`mcpc_ucbr_prmptget_add_user_printf8`](#=mcpc_ucbr_prmptget_add_user_printf8=)
    -   [`mcpc_ucbr_prmptget_add_assist_printf8`](#=mcpc_ucbr_prmptget_add_assist_printf8=)



<a id="server"></a>

# Server


<a id="=mcpc_server_t="></a>

## `mcpc_server_t`

Server instance


<a id="=mcpc_server_new_iostrm="></a>

## `mcpc_server_new_iostrm`

Create a I/O streams-base server.

    mcpc_server_t *
    mcpc_server_new_iostrm (const FILE *const strm_in, const FILE *const strm_out);

`strm_in`: input stream

`strm_out`: output stream


<a id="=mcpc_server_new_tcp="></a>

## `mcpc_server_new_tcp`

Create a TCP-based server.

    mcpc_server_t*
    mcpc_server_new_tcp ();


<a id="=mcpc_server_set_nament="></a>

## `mcpc_server_set_nament`

Set server's name.

    mcpc_errcode_t
    mcpc_server_set_nament (mcpc_server_t *sv, const char8_t *nament);

`sv`: server

`nament`: null-terminated name. Must be a UTF-8 string


<a id="=mcpc_server_capa_enable_prmt="></a>

## `mcpc_server_capa_enable_prmt`

Enable server's general capability of *Prompt*.

    mcpc_errcode_t
    mcpc_server_capa_enable_prmt (mcpc_server_t *sv);

`sv`: server


<a id="=mcpc_server_capa_enable_prmt_listchg="></a>

## `mcpc_server_capa_enable_prmt_listchg`

Enable server's capability of notification for Prompt list updates.

    mcpc_errcode_t
    mcpc_server_capa_enable_prmt_listchg (mcpc_server_t *sv);

`sv`: server


<a id="=mcpc_server_capa_enable_tool="></a>

## `mcpc_server_capa_enable_tool`

Enable server's general capability of *Prompt*.

    mcpc_errcode_t
    mcpc_server_capa_enable_tool (mcpc_server_t *sv);

`sv`: server


<a id="=mcpc_server_capa_enable_tool_listchg="></a>

## `mcpc_server_capa_enable_tool_listchg`

Enable server's capability of notification for Prompt list updates.

    mcpc_errcode_t
    mcpc_server_capa_enable_tool_listchg (mcpc_server_t *sv);

`sv`: server


<a id="=mcpc_server_capa_enable_rsc="></a>

## `mcpc_server_capa_enable_rsc`

Enable server's general capability of *Resource*.

    mcpc_errcode_t
    mcpc_server_capa_enable_rsc (mcpc_server_t *sv);

`sv`: server


<a id="=mcpc_server_capa_enable_rsc_subscr="></a>

## `mcpc_server_capa_enable_rsc_subscr`

Enable server's capability of notification for Resource subscription.

    mcpc_errcode_t
    mcpc_server_capa_enable_rsc_subscr (mcpc_server_t *sv);

`sv`: server


<a id="=mcpc_server_capa_enable_rsc_listchg="></a>

## `mcpc_server_capa_enable_rsc_listchg`

Enable server's capability of notification for Prompt list updates.

    mcpc_errcode_t
    mcpc_server_capa_enable_rsc_listchg (mcpc_server_t *sv);

`sv`: server


<a id="=mcpc_server_capa_enable_complt="></a>

## `mcpc_server_capa_enable_complt`

Enable server's general capability of *Completion*.

    mcpc_errcode_t
    mcpc_server_capa_enable_complt (mcpc_server_t *sv);

`sv`: server


<a id="=mcpc_server_add_tool="></a>

## `mcpc_server_add_tool`

Add a *Tool* to a server.

    mcpc_errcode_t
    mcpc_server_add_tool (mcpc_server_t *sv, mcpc_tool_t *tool);

`sv`: server

`tool`: tool, it will be automatically freed


<a id="=mcpc_server_add_prmpt="></a>

## `mcpc_server_add_prmpt`

Add a *Prompt* to a server.

    mcpc_errcode_t
    mcpc_server_add_prmpt (mcpc_server_t *sv, mcpc_prmpt_t *prmpt);

`sv`: server

`prmpt`: prompt, it will be automatically freed


<a id="=mcpc_server_add_rsc="></a>

## `mcpc_server_add_rsc`

Add a *Resource* to a server.

    mcpc_errcode_t
    mcpc_server_add_rsc (mcpc_server_t *sv, mcpc_rsc_t *rsc);

`sv`: server

`prmpt`: prompt, it will be automatically freed


<a id="=mcpc_server_start="></a>

## `mcpc_server_start`

Start a server.

    mcpc_errcode_t
    mcpc_server_start (mcpc_server_t *sv);

`sv`: server


<a id="=mcpc_server_close="></a>

## `mcpc_server_close`

Close a server.

    mcpc_errcode_t
    mcpc_server_close (mcpc_server_t *sv);

`sv`: server


<a id="org386a1c2"></a>

# Tool


<a id="=mcpc_tool_t="></a>

## `mcpc_tool_t`

Tool


<a id="=mcpc_toolprop_t="></a>

## `mcpc_toolprop_t`

Tool property


<a id="=mcpc_tcallcb_t="></a>

## `mcpc_tcallcb_t`

The callback function of while doing tool calling.


<a id="=mcpc_toolprop_new="></a>

## `mcpc_toolprop_new`

    mcpc_toolprop_t *
    mcpc_toolprop_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len, mcpc_anytype_t typ);

`name`: *tool* property's name

`name_len`: the length of *tool* property's name

`desc`: *tool* property's description

`desc_len`: the length of *tool* property's description


<a id="=mcpc_toolprop_new2="></a>

## `mcpc_toolprop_new2`

    mcpc_toolprop_t *
    mcpc_toolprop_new2 (const char8_t *nament, const char8_t *descnt, mcpc_anytype_t typ);

`nament`: *tool* property's name, must be null-terminated

`descnt`: *tool* property's description, must be null-terminated


<a id="=mcpc_tool_new="></a>

## `mcpc_tool_new`

    mcpc_tool_t *
    mcpc_tool_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len);

`name`: *tool*'s name

`name_len`: the length of *tool*'s name

`desc`: *tool*'s description

`desc_len`: the length of *tool*'s description


<a id="=mcpc_tool_new2="></a>

## `mcpc_tool_new2`

    mcpc_tool_t *
    mcpc_tool_new2 (const char8_t *nament, const char8_t *descnt);

`nament`: *tool*'s name, must be null-terminated

`descnt`: *tool*'s description, must be null-terminated


<a id="=mcpc_tool_addfre_toolprop="></a>

## `mcpc_tool_addfre_toolprop`

    void
    mcpc_tool_addfre_toolprop (mcpc_tool_t *tool, mcpc_toolprop_t *toolprop);

`tool`: *tool*

`toolprop`: *tool* property


<a id="=mcpc_tool_addcpy_toolprop="></a>

## `mcpc_tool_addcpy_toolprop`

    void
    mcpc_tool_addcpy_toolprop (mcpc_tool_t *tool, mcpc_toolprop_t *toolprop);

`tool`: *tool*

`toolprop`: *tool* property


<a id="=mcpc_tool_add_toolprop="></a>

## `mcpc_tool_add_toolprop`

Alias of `mcpc_tool_addfre_toolprop`


<a id="=mcpc_tool_get_toolprop="></a>

## `mcpc_tool_get_toolprop` (deprecate)

    const mcpc_toolprop_t *
    mcpc_tool_get_toolprop (const mcpc_tool_t *tool, size_t idx);

`tool`: *tool*


<a id="=mcpc_tool_get_toolprop_len="></a>

## `mcpc_tool_get_toolprop_len`

    size_t
    mcpc_tool_get_toolprop_len (const mcpc_tool_t *tool);

`tool`: *tool*


<a id="=mcpc_tool_get_next_toolprop="></a>

## `mcpc_tool_get_next_toolprop`

    const mcpc_toolprop_t *
    mcpc_tool_get_next_toolprop (const mcpc_tool_t *tool);

`tool`: *Tool*


<a id="=mcpc_tool_get_tpropval_i32="></a>

## `mcpc_tool_get_tpropval_i32`

    mcpc_errcode_t
    mcpc_tool_get_tpropval_i32 (const mcpc_tool_t *tool, const char8_t *tprop_nament, int32_t *ret);

`tool`: *tool*

`tprop_nament`: *tool* property's name, null-terminated

`ret`: the value of *tool* property


<a id="=mcpc_tool_get_tpropval_u8str="></a>

## `mcpc_tool_get_tpropval_u8str`

    mcpc_errcode_t
    mcpc_tool_get_tpropval_u8str (const mcpc_tool_t *tool, const char8_t *tprop_nament, char8_t *ret, size_t ret_cap, size_t *ret_len);

`tool`: *tool*

`tprop_nament`: *tool* property's name, null-terminated

`ret`: the value of *tool* property


<a id="=mcpc_tool_get_call_cb="></a>

## `mcpc_tool_get_call_cb`

    mcpc_errcode_t
    mcpc_tool_get_call_cb (const mcpc_tool_t *tool, mcpc_tcallcb_t *ret);

`tool`: *tool*

`ret`: the callback for *tools/call*


<a id="=mcpc_tool_set_call_cb="></a>

## `mcpc_tool_set_call_cb`

    mcpc_errcode_t
    mcpc_tool_set_call_cb (mcpc_tool_t *tool, mcpc_tcallcb_t cb);

`tool`: *tool*

`ret`: the callback for *tools/call*


<a id="=mcpc_toolcall_result_add_text_printf8="></a>

## `mcpc_toolcall_result_add_text_printf8`

Add a text content to the result of *tools/call*.

Alias of `mcpc_ucbr_toolcall_add_text_printf8`.  


<a id="=mcpc_toolcall_result_add_errmsg_printf8="></a>

## `mcpc_toolcall_result_add_errmsg_printf8`

Add a error message to the result of *tools/call*. This will mark the
whole result as an error.

Alias of `mcpc_toolcall_result_add_errmsg_printf8`.


<a id="org52ee5a7"></a>

# Resource


<a id="=mcpc_rsc_t="></a>

## `mcpc_rsc_t`

Resource


<a id="=mcpc_rsc_new="></a>

## `mcpc_rsc_new`

    mcpc_rsc_t *
    mcpc_rsc_new (const char8_t *uri, const size_t uri_len, const char8_t *name, const size_t name_len);

`uri`: *Resource*'s URI

`uri_len`: the length of *Resource*'s URI

`name`: *Resource*'s name

`name_len`: the length of *Resource*'s name


<a id="=mcpc_rsc_new2="></a>

## `mcpc_rsc_new2`

    mcpc_rsc_t *
    mcpc_rsc_new2 (const char8_t *uri_nt, const char8_t *nament);

`uri_nt`: *Resource*'s URI, must be null-terminated

`nament`: *Resource*'s name, must be null-terminated


<a id="=mcpc_rsc_new3="></a>

## `mcpc_rsc_new3`

    mcpc_rsc_t *
    mcpc_rsc_new3 (mcpc_mime_t mime, const char8_t *uri_nt, const char8_t *nament);

`mime`:  *Resource*'s MIME type

`uri_nt`: *Resource*'s URI, must be null-terminated

`nament`: *Resource*'s name, must be null-terminated


<a id="=mcpc_rsc_free="></a>

## `mcpc_rsc_free`

    void
    mcpc_rsc_free (mcpc_rsc_t *rsc);

`rsc`: *Resource*


<a id="=mcpc_rsc_get_uri="></a>

## `mcpc_rsc_get_uri`

    mcpc_errcode_t
    mcpc_rsc_get_uri (const mcpc_rsc_t *rsc, char8_t *ret, size_t ret_cap, size_t *ret_len);

`rsc`: *Resource*


<a id="=mcpc_rsc_getref_uri="></a>

## `mcpc_rsc_getref_uri`

    mcpc_errcode_t
    mcpc_rsc_getref_uri (const mcpc_rsc_t *rsc, const char8_t **ret, size_t *ret_len);

`rsc`: *Resource*.

`ret`: the pointer to *Resource*'s URI.

`ret_len`: the length of *Resource*'s URI.


<a id="=mcpc_rsc_getref_name="></a>

## `mcpc_rsc_getref_name`

    mcpc_errcode_t
    mcpc_rsc_getref_name (const mcpc_rsc_t *rsc, const char8_t **ret, size_t *ret_len);

`rsc`: *Resource*.

`ret`: the pointer to *Resource*'s name.

`ret_len`: the length of *Resource*'s name.


<a id="=mcpc_rsc_get_mime="></a>

## `mcpc_rsc_get_mime`

    mcpc_errcode_t
    mcpc_rsc_get_mime (const mcpc_rsc_t *rsc, mcpc_mime_t *ret);

`rsc`: *Resource*.

`ret`: *Resource*'s MIME type.


<a id="org211140d"></a>

# Prompt


<a id="=mcpc_prmpt_t="></a>

## `mcpc_prmpt_t`

Prompt


<a id="=mcpc_prmptarg_t="></a>

## `mcpc_prmptarg_t`

prompt argument


<a id="=mcpc_prmptarghint_t="></a>

## `mcpc_prmptarghint_t`

prompt argument hint


<a id="=mcpc_prmpt_callcb_t="></a>

## `mcpc_prmpt_callcb_t`

callback for prompts/get


<a id="=mcpc_prmptarg_new="></a>

## `mcpc_prmptarg_new`

    mcpc_prmptarg_t *
    mcpc_prmptarg_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len);

`name`: *Prompt* argument's name

`name_len`: the length of *Prompt* argument's name

`desc`: *Prompt* argument's description

`desc_len`: the length of *Prompt* argument's description


<a id="=mcpc_prmptarg_new2="></a>

## `mcpc_prmptarg_new2`

    mcpc_prmptarg_t *
    mcpc_prmptarg_new2 (const char8_t *nament, const char8_t *descnt);

`nament`: *Prompt* argument's name, must be null-terminated

`descnt`: *Prompt* argument's description, must be null-terminated


<a id="=mcpc_prmptarg_new3="></a>

## `mcpc_prmptarg_new3`

    mcpc_prmptarg_t *
    mcpc_prmptarg_new3 (const char8_t *nament);

`nament`: *Prompt* argument's name, must be null-terminated


<a id="=mcpc_prmpt_new="></a>

## `mcpc_prmpt_new`

    mcpc_prmpt_t *
    mcpc_prmpt_new (const char8_t *name, const size_t name_len, const char8_t *desc, const size_t desc_len);

`name`: *Prompt*'s name

`name_len`: the length of *Prompt*'s name

`desc`: *Prompt*'s description

`desc_len`: the length of *Prompt*'s description


<a id="=mcpc_prmpt_new2="></a>

## `mcpc_prmpt_new2`

    mcpc_prmpt_t *
    mcpc_prmpt_new2 (const char8_t *nament, const char8_t *descnt);

`nament`: *Prompt*'s name, must be null-terminated

`descnt`: *Prompt*'s description, must be null-terminated


<a id="=mcpc_prmpt_new3="></a>

## `mcpc_prmpt_new3`

    mcpc_prmpt_t *
    mcpc_prmpt_new3 (const char8_t *nament);

`nament`: *Prompt*'s name, must be null-terminated


<a id="=mcpc_prmpt_addfre_prmptarg="></a>

## `mcpc_prmpt_addfre_prmptarg`

    mcpc_errcode_t
    mcpc_prmpt_addfre_prmptarg (mcpc_prmpt_t *prmpt, mcpc_prmptarg_t *prmptarg);

`prmpt`: *Prompt*

`prmptarg`: *Prompt* argument


<a id="=mcpc_prmpt_addcpy_prmptarg="></a>

## `mcpc_prmpt_addcpy_prmptarg`

    void
    mcpc_prmpt_addcpy_prmptarg (mcpc_prmpt_t *prmpt, mcpc_prmptarg_t *prmptarg);

`prmpt`: *Prompt*

`prmptarg`: *Prompt* argument


<a id="=mcpc_prmpt_add_prmptarg="></a>

## `mcpc_prmpt_add_prmptarg`

Alias of `mcpc_prmpt_addfre_prmptarg`.


<a id="=mcpc_prmpt_get_prmptarg="></a>

## `mcpc_prmpt_get_prmptarg` (deprecated)

    const mcpc_prmptarg_t *
    mcpc_prmpt_get_prmptarg (const mcpc_prmpt_t *prmpt, size_t idx);

`prmpt`: *Prompt*

`idx`: &#x2026;


<a id="=mcpc_prmpt_get_prmptarg_len="></a>

## `mcpc_prmpt_get_prmptarg_len`

    size_t
    mcpc_prmpt_get_prmptarg_len (const mcpc_prmpt_t *prmpt);

`prmpt`: *Prompt*


<a id="=mcpc_prmpt_get_next_prmptarg="></a>

## `mcpc_prmpt_get_next_prmptarg`

    const mcpc_prmptarg_t *
    mcpc_prmpt_get_next_prmptarg (const mcpc_prmpt_t *prmpt);

`prmpt`: *Prompt*


<a id="=mcpc_prmpt_getbyname_prmptarg="></a>

## `mcpc_prmpt_getbyname_prmptarg`

    const mcpc_prmptarg_t *
    mcpc_prmpt_getbyname_prmptarg (const mcpc_prmpt_t *prmpt, const char8_t *parg_name, size_t parg_name_len);

`prmpt`: *Prompt*

`parg_name`: *Prompt* argument's name

`parg_name_len`: the length of *Prompt* argument's name


<a id="=mcpc_prmpt_getbynament_prmptarg="></a>

## `mcpc_prmpt_getbynament_prmptarg`

    const mcpc_prmptarg_t *
    mcpc_prmpt_getbynament_prmptarg (const mcpc_prmpt_t *prmpt, const char8_t *parg_nament);

`prmpt`: *Prompt*

`parg_nament`: *Prompt* argument's name, must be null-terminated


<a id="=mcpc_prmpt_get_callcb="></a>

## `mcpc_prmpt_get_callcb`

    mcpc_errcode_t
    mcpc_prmpt_get_callcb (const mcpc_prmpt_t *prmpt, mcpc_prmpt_callcb_t *ret);

`prmpt`: *Prompt*

`ret`: the callback for *prompts/get*


<a id="=mcpc_prmpt_set_callcb="></a>

## `mcpc_prmpt_set_callcb`

    mcpc_errcode_t
    mcpc_prmpt_set_callcb (mcpc_prmpt_t *prmpt, mcpc_prmpt_callcb_t cb);

`prmpt`: *prompt*

`ret`: the callback for *prompts/get*


<a id="=mcpc_prmptarg_get_u8str="></a>

## `mcpc_prmptarg_get_u8str`

    mcpc_errcode_t
    mcpc_prmptarg_get_u8str (const mcpc_prmptarg_t *prmptarg, char8_t *ret, size_t ret_cap, size_t *ret_len);

`prmptarg`: *prompt* argument

`ret`: caller-provided buffer

`ret_cap`: the buffer's capacity

`ret_len`: the buffer's length


<a id="=mcpc_prmptarg_getref_u8str="></a>

## `mcpc_prmptarg_getref_u8str`

    mcpc_errcode_t
    mcpc_prmptarg_getref_u8str (const mcpc_prmptarg_t *prmptarg, const char8_t **ret, size_t *ret_len);

`prmptarg`: *prompt* argument

`ret`: the pointer to prompt's argument string data

`ret_len`: the length of prompt's argument string data


<a id="=mcpc_prmptarg_add_hint_printf8="></a>

## `mcpc_prmptarg_add_hint_printf8`

    mcpc_errcode_t
    mcpc_prmptarg_add_hint_printf8 (mcpc_prmptarg_t *prmptarg, const char8_t *fmt, ...);

`prmptarg`: *prompt* argument

`fmt`: the format string to print


<a id="=mcpc_prmptget_result_add_user_printf8="></a>

## `mcpc_prmptget_result_add_user_printf8`

Add a complete <span class="underline">user</span> prompt to the result of *prompts/get*.

Alias of `mcpc_ucbr_prmptget_add_user_printf8`. 


<a id="=mcpc_prmptget_result_add_assist_printf8="></a>

## `mcpc_prmptget_result_add_assist_printf8`

Add a complete <span class="underline">assistant</span> prompt to the result of *prompts/get*.

Alias of `mcpc_ucbr_prmptget_add_assist_printf8`. 


<a id="org6f84d9e"></a>

# Others


<a id="=mcpc_"></a>

## `mcpc_errcode_t`

Library-specific error codes.


### Possible values

`MCPC_EC_0`: success

`MCPC_EC_BUG`: bug

`MCPC_EC_BUFCAP`: insufficient buffer capacity

`MCPC_EC_LONGTOOLNAME`: tool's name is too long

`MCPC_EC_LONGTOOLDESC`: tool's description is too long

`MCPC_EC_LONGTPROPNAME`: tool property's name is too long

`MCPC_EC_LONGTPROPDESC`: tool property's description is too long

`MCPC_EC_TOOLPROP_NOTFOUND`: tool property is not found

`MCPC_EC_TOOLCALL_USERERR`: after tool calling, user indicates an error

`MCPC_EC_CONNPOOL_NOTADD`: connection cannot be added

`MCPC_EC_SVIMPL_SOCKET`: fail to create TCP socket

`MCPC_EC_SVIMPL_BIND`: fail to bind TCP socket

`MCPC_EC_SVIMPL_LISTEN`: fail to listen TCP socket

`MCPC_EC_SVIMPL_TCP_INSUF_BUF`: insufficient buffer capacity

`MCPC_EC_ANYDATA_NOTFOUND`: data cannot be found

`MCPC_EC_ANYDATA_LONGNAME`: data's name is too long

`MCPC_EC_PRMPTARG_NOTFOUND`:  prompt agument cannot be found

`MCPC_EC_JSON_FIELD_INVALID`: json field's value invalid, this means
the field is missing, or field has unexpected type


<a id="=mcpc_anytype_t="></a>

## `mcpc_anytype_t`

The data type recognizable by the library.


### Possible values

`MCPC_NONE`: nothing

`MCPC_I8`: `int8_t`-like type

`MCPC_U8`: `uint8_t`-like type

`MCPC_I16`: `int16_t`-like type

`MCPC_U16`: `uint16_t`-like type

`MCPC_I32`: `int32_t`-like type

`MCPC_U32`: `uint32_t`-like type

`MCPC_I64`: `int64_t`-like type

`MCPC_U64`: `uint64_t`-like type

`MCPC_U8STR`: string of UTF-8 code units

`MCPC_I8S`: an array of `int8_t`

`MCPC_U8S`: an array of `uint8_t`

`MCPC_I16S`: an array of `int16_t`

`MCPC_U16S`: an array of `uint16_t`

`MCPC_I32S`: an array of `int32_t`

`MCPC_U32S`: an array of `uint32_t`

`MCPC_I64S`: an array of `int64_t`

`MCPC_U64S`: an array of `uint64_t`

`MCPC_FUNC`: a function


<a id="=mcpc_mime_t="></a>

## `mcpc_mime_t`

MIME types recognizable by the library, that conforms to [RFC2045](https://www.rfc-editor.org/rfc/rfc2045).


### Possible value

`MCPC_MIME_NONE`: nothing

`MCPC_MIME_TEXT_PLAIN`: text/plain

`MCPC_MIME_IMAGE_PNG`: image/png

`MCPC_MIME_IMAGE_JPEG`: image/jpeg

`MCPC_MIME_IMAGE_GIF`: image/gif

`MCPC_MIME_AUDIO_MPEG`: audio/mpeg

`MCPC_MIME_AUDIO_WAV`: audio/wav

`MCPC_MIME_VIDEO_MPEG`: video/mpeg

`MCPC_MIME_VIDEO_AVI`: video/avi

`MCPC_MIME_APPLI_OCTS`: application/octet-stream

`MCPC_MIME_APPLI_JSON`: application/json

`MCPC_MIME_APPLI_PDF`: application/pdf


<a id="=mcpc_ucbr_t="></a>

## `mcpc_ucbr_t`

User call back result.


<a id="=mcpc_ucbr_toolcall_add_text_printf8="></a>

## `mcpc_ucbr_toolcall_add_text_printf8`

Add a text message to the result of *tools/call*.

    void
    mcpc_ucbr_toolcall_add_text_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt, ...);

`ucbr`: the callback result

`fmt`: format string to be printed


<a id="=mcpc_ucbr_toolcall_add_errmsg_printf8="></a>

## `mcpc_ucbr_toolcall_add_errmsg_printf8`

Add a error message to the result of *tools/call*.

    void
    mcpc_ucbr_toolcall_add_errmsg_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt, ...);

`ucbr`: the callback result

`fmt`: format string to be printed


<a id="=mcpc_ucbr_prmptget_add_user_printf8="></a>

## `mcpc_ucbr_prmptget_add_user_printf8`

Add a user prompt to the result of *prompts/get*.

    void
    mcpc_ucbr_prmptget_add_user_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt, ...);

`ucbr`: the callback result

`fmt`: format string to be printed


<a id="=mcpc_ucbr_prmptget_add_assist_printf8="></a>

## `mcpc_ucbr_prmptget_add_assist_printf8`

Add an assistant prompt to the result of *prompts/get*.

    void
    mcpc_ucbr_prmptget_add_assist_printf8 (mcpc_ucbr_t *ucbr, const char8_t *fmt, ...);

`ucbr`: the callback result

`fmt`: format string to be printed

