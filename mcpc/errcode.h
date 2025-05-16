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

#ifndef h_pub_errcode
#define h_pub_errcode

enum mcpc_errcode
{
  MCPC_EC_0 = 0,
  MCPC_EC_BUG,
  MCPC_EC_BUFCAP,
  MCPC_EC_ANYDATA_LONGMETA1,
  MCPC_EC_ANYDATA_LONGMETA2,
  MCPC_EC_LONGTOOLNAME,
  MCPC_EC_LONGTOOLDESC,
  MCPC_EC_LONGTPROPNAME,
  MCPC_EC_LONGTPROPDESC,
  MCPC_EC_TOOLPROP_NOTFOUND,
  MCPC_EC_TOOLCALL_USERERR,
  MCPC_EC_CONNPOOL_NOTADD,
  MCPC_EC_SVIMPL_SOCKET,
  MCPC_EC_SVIMPL_BIND,
  MCPC_EC_SVIMPL_LISTEN,
  MCPC_EC_SVIMPL_TCP_INSUF_BUF,
  MCPC_EC_ANYDATA_NOTFOUND,
  MCPC_EC_ANYDATA_LONGNAME,
  MCPC_EC_PRMPTARG_NOTFOUND,
  MCPC_EC_JSON_FIELD_INVALID,
};
typedef enum mcpc_errcode mcpc_errcode_t;

#endif
