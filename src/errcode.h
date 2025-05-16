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

#ifndef h_errcode
#define h_errcode


#include <mcpc/errcode.h>
#include <mcpc/_c23_keywords.h>



// [[maybe_unused]] static mcpc_errcode_t mcpc_ec = MCPC_EC_CONNPOOL_NOTADD;
// useless: after abort(), p mcpc_ec is always default value
extern mcpc_errcode_t mcpc_ec;

// [[noreturn]] ???
void
mcpc_assert(const bool cond, const mcpc_errcode_t ec);


static inline void bug_if_nullptr(const void *ptr)
{
    if (ptr == nullptr)
    {
        mcpc_assert(false, MCPC_EC_BUG);
    }
}

static inline void bug_if_zero(const unsigned long long ptr)
{
    if (ptr == 0)
    {
        mcpc_assert(false, MCPC_EC_BUG);
    }
}

static inline void bug_if_nz(const unsigned long long ptr)
{
    if (ptr != 0)
    {
        mcpc_assert(false, MCPC_EC_BUG);
    }
}


static inline void bug_if(bool f)
{
    if (f)
    {
        mcpc_assert(false, MCPC_EC_BUG);
    }
}


#endif
