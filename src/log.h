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

#ifndef h_log
#define h_log

#include <stdarg.h>
#include <stdio.h>

typedef enum
{
    Error = 1,
    Info,
    Debug,
} LogLevel;

extern LogLevel glv; // TODO: thread-safety

#ifdef MCPC_DBG
#define tulog_d(...)                                                                                                   \
    do                                                                                                                 \
    {                                                                                                                  \
        char meta[100];                                                                                                \
        sprintf(meta, "%s,%d", __TU__, __LINE__);                                                                      \
        lvlog(Debug, meta, stderr __VA_OPT__(, ) __VA_ARGS__);                                                         \
    } while (false)
#define tuflog_d(...)                                                                                                  \
    do                                                                                                                 \
    {                                                                                                                  \
        FILE *logf = fopen("/tmp/mcpc.log", "a");                                                                      \
        char meta[100];                                                                                                \
        sprintf(meta, "%s,%d", __TU__, __LINE__);                                                                      \
        lvlog(Debug, meta, logf __VA_OPT__(, ) __VA_ARGS__);                                                           \
    } while (false)
#else
#define tulog_d(...) ;
#define tuflog_d(...) ;
#endif

void lvlog(LogLevel lv, const char *meta, FILE *stream, const char *format, ...);

#endif
