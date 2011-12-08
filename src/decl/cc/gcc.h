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
#ifndef DECL_CC_GCC_H_
#define DECL_CC_GCC_H_

#include <decl/c.h>
DECL_BEGIN_C
#include <decl/config.h>

#if ! PLAT_CC_GCC
#   error "don't manually include this file: it's for gcc only"
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(3,3,0)
# if !PLAT_C
#  define DECL_EXPORT_T __attribute__((visibility("default")))
#  define DECL_HIDE_T  __attribute__((visibility("hidden")))
# endif
#  define DECL_EXPORT_FN __attribute__((visibility("default")))
#  define DECL_HIDE_FN __attribute__((visibility("hidden")))
#  define DECL_EXPORT_VAR __attribute__((visibility("default")))
#  define DECL_HIDE_VAR __attribute__((visibility("hidden")))
#endif

#define DECL_INLINE __inline__

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(3, 1, 0)
#   define DECL_FORCE_INLINE    __attribute__((always_inline))
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(3, 1, 0)
#   define DECL_NEVER_INLINE    __attribute__((noinline))
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(3, 1, 0)
#   define DECL_PURE    __attribute__((pure))
#endif

/* should it be 2.5.0?
 * see: http://www.ohse.de/uwe/articles/gcc-attributes.html#func-const
 */
#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(2, 6, 0)
#   define DECL_CONST   __attribute__((const))
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(2, 5, 0)
#   define DECL_NORETURN    __attribute__((noreturn))
#endif

#define DECL_MALLOC  __attribute__((malloc))

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(3, 0, 0)
#define DECL_CHECK_RESULT    __attribute__((warn_unused_result))
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(3, 1, 0)
#   define DECL_DEPRECATED  __attribute__((deprecated))
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(3, 1, 0)
#  define DECL_USED    __attribute__((used))
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(2, 7, 0)
#  define DECL_UNUSED  __attribute__((unused))
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(3, 0, 0)
#  define DECL_LIKELY(x)   __builtin_expect(!!(x), 1)
#  define DECL_UNLIKELY(x) __builtin_expect(!!(x), 0)
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(3, 0, 0)
#  define DECL_FUNCSIG    __PRETTY_FUNCTION__
#endif

#if PLAT_CC_GCC_VER >= PLAT_CC_GCC_MAKE_VER(4, 3, 0)
#  define DECL_ALIGN(newtype, type, size)  typedef type newtype __attribute__((aligned(size)));
#endif

DECL_END_C
#endif
