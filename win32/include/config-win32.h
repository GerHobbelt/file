/*
 * Copyright (c) Ian F. Darwin 1986-1995.
 * Software written by Ian F. Darwin and others;
 * maintained 1995-present by Christos Zoulas and others;
 * win32 native (Visual Studio-compatible) port by Albert Huang and others.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice immediately at the beginning of the file, without modification,
 *    this list of conditions, and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
/* 
 * Native Win32 header for building with Visual Studio.
 * This file will only get included when building with VS.
 * It shouldn't be included when building on Win32 via Cygwin/MinGW.
 */

#ifndef _CONFIG_WIN32_H_
#define _CONFIG_WIN32_H_

/* Mute any warnings from VC++ */
#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif

/* Include sys/stat.h shim */
#include "win32_stat.h"

/* Include necessary IO headers (open, read, close, write, access) */
#include <io.h>
#include <string.h>

/* Include headers necessary for making custom (v)snprintf work */
#if defined(_MSC_VER) && _MSC_VER < 1900
#include <stdio.h>
#include <stdarg.h>
#endif

/* Version number of package */
#define VERSION "5.25"

/* Make the source aware of available compile options */
#define HAVE_STDINT_H
#define HAVE_STRERROR
#define HAVE_LOCALE_H
#define HAVE_NEWLOCALE
#define HAVE_STRTOUL

/* This allows ZLIB support to be enabled.
 * NOTE: Make sure include and lib paths are correct for ZLIB!
 */
#define HAVE_ZLIB_H
#define HAVE_LIBZ

/* Enable getopt */
#define REPLACE_GETOPT
extern int optind;
extern char *optarg;

/* Workarounds for making this compile on MSVC++ 10! */
#ifndef R_OK
#define R_OK 4
#endif

#ifndef W_OK
#define W_OK 2
#endif

#ifndef X_OK
#define X_OK 0
#endif

#ifndef mode_t
typedef int mode_t;
#endif

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif

#ifndef HAVE_SSIZE_T
typedef int ssize_t;
#define HAVE_SSIZE_T
#endif /* HAVE_SSIZE_T */

#define lstat stat
#define readlink(p, b, s) EINVAL

/* Redefine inline for older VS <2015 */
#if defined(_MSC_VER) && _MSC_VER < 1900
#define inline __inline
#endif

/* If we are not using VS2013 and above, define an alternative
 * workaround function. (NOTE: VS2015 = 1900, VS2013 = 1800)
 */
#if _MSC_VER < 1800
#define strtoull _strtoui64
#endif

/* Define snprintf/vsnprintf if we are using VSC++ older than VS2015. */
#if defined(_MSC_VER) && _MSC_VER < 1900
#define snprintf c99_snprintf
#define vsnprintf c99_vsnprintf

inline int c99_vsnprintf(char *outBuf, size_t size, const char *format, va_list ap)
{
    int count = -1;

    if (size != 0)
        count = _vsnprintf_s(outBuf, size, _TRUNCATE, format, ap);
    if (count == -1)
        count = _vscprintf(format, ap);

    return count;
}

inline int c99_snprintf(char *outBuf, size_t size, const char *format, ...)
{
    int count;
    va_list ap;

    va_start(ap, format);
    count = c99_vsnprintf(outBuf, size, format, ap);
    va_end(ap);

    return count;
}

#endif

#endif