#ifndef DECL_CC_MSVC_H
#define DECL_CC_MSVC_H

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
#endif /* DECL_CC_MSVC_H */

