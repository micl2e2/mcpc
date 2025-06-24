
# Table of Contents

-   [Overview](#overview)
-   [MCP Features](#features)
-   [Supported Platforms](#platforms)
-   [Modern C Support](#modernc)
-   [Building](#building)
-   [Development](#development)
-   [FAQ](#org73da0a6)
-   [License](#license)



<a id="overview"></a>

# Overview

mcpc is a <b>M</b>odel <b>C</b>ontext <b>P</b>rotocol library in modern <b>C</b>. Its major goals are:

-   Provide the **most native** bridge between low-level infrastructure
    and AI models
-   Explore the maximum capability of the **most recent** C programming language


<a id="features"></a>

# MCP Features

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">Features</th>
<th scope="col" class="org-left">Server</th>
<th scope="col" class="org-left">Client</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">Tool</td>
<td class="org-left">✅</td>
<td class="org-left">🔨</td>
</tr>


<tr>
<td class="org-left">Resource</td>
<td class="org-left">✅</td>
<td class="org-left">🔨</td>
</tr>


<tr>
<td class="org-left">Prompt</td>
<td class="org-left">✅</td>
<td class="org-left">🔨</td>
</tr>


<tr>
<td class="org-left">Completion</td>
<td class="org-left">✅</td>
<td class="org-left">🔨</td>
</tr>


<tr>
<td class="org-left">STDIO Transport</td>
<td class="org-left">✅</td>
<td class="org-left">🔨</td>
</tr>


<tr>
<td class="org-left">HTTP Transport</td>
<td class="org-left">🔨</td>
<td class="org-left">🔨</td>
</tr>


<tr>
<td class="org-left">Others</td>
<td class="org-left">🔨</td>
<td class="org-left">🔨</td>
</tr>
</tbody>
</table>


<a id="platforms"></a>

# Supported Platforms

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">&#xa0;</th>
<th scope="col" class="org-left">Linux</th>
<th scope="col" class="org-left">Windows</th>
<th scope="col" class="org-left">macOS</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">Linux</td>
<td class="org-left">✅</td>
<td class="org-left">✅</td>
<td class="org-left">✅</td>
</tr>
</tbody>
</table>

Note: this table roughly shows the state of supporting on some platforms,
for more detailed information, check the *Modern C Support*.


<a id="modernc"></a>

# Modern C Support

Since mcpc claims to implement everything with the most modern C
possible, its building process becomes a little different than many
existing building systems or process, the major
difference is that: ****we try to support as many C compilers as possible,
even on one platform****.

Ideally mcpc will be implemented fully in C23(currently the newest
standard), but if a full C23 is missing on a platform, we
either downgrade the C standard, or give up the support.

This approach certainly has some benefits and consequences:

1.  The library can launch on as many platforms as possible, and be
    able to compiled by as many C compilers as possible.
2.  There must be a minimum fallback version of C standard that the
    library targets, currently it is C11.
3.  C23 features that are not patchable, or require non-trivial amount
    of effort to patch, will not be used, e.g., [N2508](https://open-std.org/JTC1/SC22/WG14/www/docs/n2508.pdf), [N2645](https://open-std.org/JTC1/SC22/WG14/www/docs/n2645.pdf), etc.
4.  All safety checks and performance optimization will only focus on the
    platforms with full C23 support.


## Support Matrix

`✅✅` : *implemented in C23*

`🔨✅` : *implemented in C11~C17*

`-` : *the platform does not exist, or work in progress*

Linux:

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">&#xa0;</th>
<th scope="col" class="org-left">GLIBC 2.31</th>
<th scope="col" class="org-left">GLIBC 2.36</th>
<th scope="col" class="org-left">GLIBC 2.40</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">GCC 10</td>
<td class="org-left">🔨✅ (Debian 11)</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
</tr>


<tr>
<td class="org-left">GCC 12</td>
<td class="org-left">-</td>
<td class="org-left">🔨✅ (Debian 12)</td>
<td class="org-left">-</td>
</tr>


<tr>
<td class="org-left">GCC 13</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
</tr>


<tr>
<td class="org-left">GCC 14</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
<td class="org-left">✅✅ (Fedora 41)</td>
</tr>


<tr>
<td class="org-left">Clang 14</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
</tr>


<tr>
<td class="org-left">Clang 16</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
</tr>


<tr>
<td class="org-left">Clang 18</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
</tr>


<tr>
<td class="org-left">Clang 19</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
<td class="org-left">✅✅ (Fedora 41)</td>
</tr>
</tbody>
</table>

Windows:

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">&#xa0;</th>
<th scope="col" class="org-left">CMD/PS</th>
<th scope="col" class="org-left">Cygwin</th>
<th scope="col" class="org-left">MinGW</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">MSVC 19</td>
<td class="org-left">🔨✅</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
</tr>


<tr>
<td class="org-left">Clang 19</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
</tr>


<tr>
<td class="org-left">GCC 14</td>
<td class="org-left">-</td>
<td class="org-left">✅✅</td>
<td class="org-left">✅✅</td>
</tr>
</tbody>
</table>

macOS:

<table border="2" cellspacing="0" cellpadding="6" rules="groups" frame="hsides">


<colgroup>
<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />

<col  class="org-left" />
</colgroup>
<thead>
<tr>
<th scope="col" class="org-left">&#xa0;</th>
<th scope="col" class="org-left">macOS 13</th>
<th scope="col" class="org-left">macOS 14</th>
<th scope="col" class="org-left">macOS 15</th>
</tr>
</thead>

<tbody>
<tr>
<td class="org-left">Clang 14</td>
<td class="org-left">🔨✅</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
</tr>


<tr>
<td class="org-left">Clang 16</td>
<td class="org-left">-</td>
<td class="org-left">🔨✅</td>
<td class="org-left">🔨✅</td>
</tr>


<tr>
<td class="org-left">GCC 14</td>
<td class="org-left">🔨✅</td>
<td class="org-left">-</td>
<td class="org-left">-</td>
</tr>
</tbody>
</table>


<a id="building"></a>

# Building


## Building (Linux, Cygwin, MSYS2, macOS, etc.)

Prerequisites:

-   GNU Make

Then

    cd mcpc
    make && make tst && make install


## Building (Windows CMD/PS/VS)

Prerequisites:

-   Visual Studio
-   GNU Make (`winget install ezwinports.make`)

Two options to build:


### 1. Build in CMD/PS

Open "x64 Native Tools Command Prompt", then

    cd mcpc
    make && make tst


### 2. Build in Visual Studio:

"File" - "Open" - "CMake", "Build" - "Build All"

> This approach is only for the better debugging experience on Windows,
> *"Build in CMD/PS"* takes priority over this one.


<a id="development"></a>

# Development

API reference can be found at [api.md](./misc/api.md).

Dependencies:

-   [mjson](https://github.com/cesanta/mjson) (already in-tree)


## Code Contributing

Despite we claim to use modern C, as standard as possible, and as
modern as possible, we have some extra conventions, in order to render
our code more readable, inclusive and scalable:

1.  Unless mentioned explicitly, we follow GNU C [coding style](https://www.gnu.org/prep/standards/html_node/Writing-C.html).
2.  Prefer functions over macros, use macros only if necessary.
3.  The type of variables should be reflected in the source code. Use of
    keyword `auto` is thus forbidden.
4.  Names of defined variables that are exposed publicly should be in
    uppercase, otherwise in lowercase.


<a id="org73da0a6"></a>

# FAQ


## Should I prefer mcpc over other SDKs?

It depends on your use case. Roughly speaking, if

1.  you prefer your MCP servers or clients to perform tasks in the most
    native way (e.g. manually manage memory allocation, equipped with
    competitive performance, etc.).
2.  you wish your MCP servers or clients are distributed with minimum
    software requirements (i.e. you don't want to force users to
    have Python, Node.js or similar things installed on their machines)

then mcpc is for you. Otherwise I would strongly recommend you consider
Python, Javscript or other SDKs, they have more intuitive and
easy-to-use high-level APIs for MCP protocol.


<a id="license"></a>

# License

    The MIT License (MIT)
    
    Copyright (c) 2025 Michael Lee <micl2e2 AT proton.me>
    
    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions: 
    
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software. 
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

