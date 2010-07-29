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
#endif /* DECL_CC_GCC_H_ */

