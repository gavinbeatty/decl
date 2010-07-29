#ifndef DECL_DECL_H
#define DECL_DECL_H

#include <decl/c.h>
DECL_BEGIN_C
#include <decl/config.h>

#if PLAT_CC_GCC
#   include <decl/cc/gcc.h>
#elif PLAT_CC_MSVC
#   include <decl/cc/msvc.h>
#endif

#include <decl/cc/generic.h>


DECL_END_C
#endif /* DECL_DECL_H */

