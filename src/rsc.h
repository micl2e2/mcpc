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

#ifndef h_rsc
#define h_rsc

#include <stddef.h>
#include <stdio.h>

#include <mcpc/_c23_keywords.h>
#include <mcpc/_c23_uchar.h>

#include <mcpc/rsc.h>

typedef mcpc_anypool_t mcpc_rscpool_t;

// ---------------------------- rscpool ----------------------------

mcpc_rscpool_t *mcpc_rscpool_new ();

void mcpc_rscpool_free (mcpc_rscpool_t * rscpool);

void mcpc_rscpool_add_cp (mcpc_rscpool_t * rscpool, const mcpc_rsc_t * tmp_rsc);

void mcpc_rscpool_addfre (mcpc_rscpool_t * rscpool, mcpc_rsc_t * tmp_rsc);

const mcpc_rsc_t *mcpc_rscpool_get_const (const mcpc_rscpool_t * rscpool, size_t idx);

const mcpc_rsc_t *mcpc_rscpool_get_next (const mcpc_rscpool_t * rscpool);

const mcpc_rsc_t *mcpc_rscpool_getbyname (const mcpc_rscpool_t * rscpool, const char8_t * name, size_t name_len);

#endif
