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

#ifndef h_server
#define h_server

#include <mcpc/visb.h>
#include <mcpc/server.h>

#include "ext_stdint.h"

#include "errcode.h"
#include "mjson.h"
#include "rsc.h"
#include "tool.h"
#include "prmpt.h"

#include <stdio.h>

#if is_win
#include <winsock2.h>
typedef i32_t socklen_t;
#endif

#define BUFFER_SIZE 1024
#define PORT 8080

// ------------------------------ conn ------------------------------

enum mcpc_conn_type
{
  MCPC_CONN_FD,
  MCPC_CONN_STRM,
};
typedef enum mcpc_conn_type mcpc_conn_type_t;

#if defined(is_unix)
typedef int mcpc_sock_t;
#elif is_win
typedef SOCKET mcpc_sock_t;
#endif

static inline bool
mcpc_sock_invalid (mcpc_sock_t sock)
{
#if defined(is_unix)
  return sock < 0;
#endif
#if is_win
  return sock == INVALID_SOCKET;
#endif
}

enum mcpc_init_stat
{
  MCPC_INIT_NONE = 0,
  MCPC_INIT_BEG,
  MCPC_INIT_FAIL,
  MCPC_INIT_SUCC,
};
typedef enum mcpc_init_stat mcpc_init_stat_t;

typedef struct mcpc_conn mcpc_conn_t;
struct mcpc_conn
{
  mcpc_conn_type_t typ;
  union
  {
    mcpc_sock_t fd;
    FILE *strm;
  };
  const ch8_t *cname;
  u8_t cname_len;
  mcpc_init_stat_t client_init;
  mcpc_conn_t *nex;
};

typedef uint8_t mcpc_connpool_size_t;

typedef struct mcpc_connpool mcpc_connpool_t;
struct mcpc_connpool
{
  const mcpc_connpool_size_t cap;
  mcpc_connpool_size_t len;
  mcpc_conn_t *head;
};

// ----------------------------- server -----------------------------

enum mcpc_server_type
{
  MCPC_SV_NONE = 0,
  MCPC_SV_IOSTRM,
  MCPC_SV_STDIO,
  MCPC_SV_TCP,
};
typedef enum mcpc_server_type mcpc_server_type_t;

struct mcpc_server
{
  mcpc_server_type_t typ;
  const ch8_t *name;
  u8_t name_len;
  const ch8_t *ver;
  u8_t ver_len;
  u16_t capa;
  const mcpc_toolpool_t *toolpool;
  const mcpc_prmptpool_t *prmptpool;
  const mcpc_rscpool_t *rscpool;
  struct mjson_fixedbuf rpcres;
  const mcpc_connpool_t *connpool;
};
// implication: for iostrm server, the first conn will be used as client init status storing
// check mcpc_connpool_find_by_sock

#define MCPC_CAPA_PRMT         0b0000000000000001
#define MCPC_CAPA_PRMT_LISTCHG 0b0000000000000011
#define MCPC_CAPA_TOOL         0b0000000000010000
#define MCPC_CAPA_TOOL_LISTCHG 0b0000000000110000
#define MCPC_CAPA_RSC          0b0000000100000000
#define MCPC_CAPA_RSC_LISTCHG  0b0000001100000000
#define MCPC_CAPA_RSC_SUBSRC   0b0000010100000000
#define MCPC_CAPA_COMPLT       0b0001000000000000

#define _FIRST_TOOL_NAME u8c1("mcpc-info")
#define _FIRST_TOOL_DESC u8c1("description: MCP protocol in C implementation; version: 0.1")

mcpc_server_t *mcpc_server_new (mcpc_server_type_t typ, mcpc_toolpool_t * toolpool, u32_t vargs_beg, ...);

mcpc_server_t *mcpc_server_new_stdio ();

/* void _handle_tools_list(mcpc_server_t *sv, struct jsonrpc_request *r); */

/* void _handle_tools_call(mcpc_server_t *sv, struct jsonrpc_request *r); */

mcpc_errcode_t mcpc_server_cleanup_rpcres (mcpc_server_t * sv);

void handle_inone (mcpc_server_t * sv, const char *const rbuf, size_t nread, mcpc_sock_t csock);

bool mcpc_server_supp_prompts (const mcpc_server_t * sv);

bool mcpc_server_supp_prompts_lschg (const mcpc_server_t * sv);

bool mcpc_server_supp_tools (const mcpc_server_t * sv);

bool mcpc_server_supp_tools_lschg (const mcpc_server_t * sv);

bool mcpc_server_supp_rscs (const mcpc_server_t * sv);

bool mcpc_server_supp_rscs_lschg (const mcpc_server_t * sv);

bool mcpc_server_supp_rscs_subs (const mcpc_server_t * sv);

enum mcpc_metho
{
  MCPC_METHO_UNKNOWN = 0,
  MCPC_METHO_INITBEG,
  MCPC_METHO_INITDONE,
  MCPC_METHO_LISTTOOL,
  MCPC_METHO_CALLTOOL,
  MCPC_METHO_LSRSC,
  MCPC_METHO_PRMPT_LS,
  MCPC_METHO_PRMPT_CALL,
  MCPC_METHO_COMPLT_COMPLT,
};
typedef enum mcpc_metho mcpc_metho_t;

// ---------------------------- connpool ----------------------------

mcpc_conn_t *mcpc_conn_new (mcpc_conn_type_t typ, void *back);

FILE *mcpc_conn_getstrm (mcpc_conn_t * conn);

int mcpc_conn_getfd (mcpc_conn_t * conn);

// TODO private
mcpc_errcode_t mcpc_connpool_addref (mcpc_connpool_t * connpool, mcpc_conn_t * conn);

mcpc_conn_t *mcpc_connpool_getconn (const mcpc_connpool_t * connpool, const mcpc_connpool_size_t idx);

#endif
