/**
Copyright (c) 2010, 2011, Gavin Beatty <gavinbeatty@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

  Neither the name of Gavin Beatty nor the names of decl's contributors may be
  used to endorse or promote products derived from this software without specific
  prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef DECL_CC_MSVC_H_
#define DECL_CC_MSVC_H_

#include <decl/c.h>
DECL_BEGIN_C
#include <decl/config.h>

#if ! DECL_CC_MSVC
#   error "don't include this file manually: it's for Microsoft Visual C compiler only"
#endif

#define DECL_EXPORT_T __declspec(dllexport)
#define DECL_IMPORT_T __declspec(dllimport)
#define DECL_EXPORT_FN __declspec(dllexport)
#define DECL_IMPORT_FN __declspec(dllimport)
#define DECL_EXPORT_VAR __declspec(dllexport)
#define DECL_IMPORT_VAR __declspec(dllimport)

#define DECL_FUNCSIG    __FUNCSIG__
#define DECL_ALIGN(newtype, type, size) typedef __declspec(align(size)) type newtype;
#define DECL_DEPRECATED __declspec(deprecated)
#define DECL_MALLOC __declspec(restrict)
#define DECL_NORETURN __declspec(noreturn)
#define DECL_NEVER_INLINE __declspec(noinline)
#define DECL_FORCE_INLINE __forceinline
#define DECL_INLINE __inline

DECL_END_C
#endif
