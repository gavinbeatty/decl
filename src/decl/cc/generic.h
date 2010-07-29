#ifndef DECL_CC_GENERIC_H_
#define DECL_CC_GENERIC_H_

#include <decl/c.h>
DECL_BEGIN_C
#include <decl/config.h>
#include <plat/cc.h>

/* \code
     #ifdef BUILDING_MY_PROJECT
     #  define PUBLIC_T DECL_EXPORT_T
     #else
     #  define PUBLIC_T DECL_IMPORT_T
     #endif

     class PUBLIC_T A { ... };
   \endcode
 */
#ifndef DECL_EXPORT_T
#define DECL_EXPORT_T /* no DECL_EXPORT_T */
#endif
/* \sa DECL_EXPORT_T */
#ifndef DECL_IMPORT_T
#define DECL_IMPORT_T /* no DECL_IMPORT_T */
#endif
/* \code
     class DECL_HIDE_T Private { ... };
   \endcode
 */
#ifndef DECL_HIDE_T
#define DECL_HIDE_T  /* no DECL_HIDE_T */
#endif
/* \code
     #ifdef BUILDING_MY_PROJECT
     #  define PUBLIC_FN DECL_EXPORT_FN
     #else
     #  define PUBLIC_FN DECL_IMPORT_FN
     #endif

     PUBLIC_FN void f(void);
   \endcode
 */
#ifndef DECL_EXPORT_FN
#define DECL_EXPORT_FN /* no DECL_EXPORT_FN */
#endif
/* \sa DECL_EXPORT_FN */
#ifndef DECL_IMPORT_FN
#define DECL_IMPORT_FN /* no DECL_IMPORT_FN */
#endif
/* \code
     DECL_HIDE_FN void backendfn(void);
   \endcode
 */
#ifndef DECL_HIDE_FN
#define DECL_HIDE_FN  /* no DECL_HIDE_FN */
#endif
/* \code
     #ifdef BUILDING_MY_PROJECT
     #  define PUBLIC_VAR DECL_EXPORT_VAR
     #else
     #  define PUBLIC_VAR DECL_IMPORT_VAR
     #endif

     extern PUBLIC_VAR int global;
   \endcode
 */
#ifndef DECL_EXPORT_VAR
#define DECL_EXPORT_VAR /* no DECL_EXPORT_VAR */
#endif
#ifndef DECL_IMPORT_VAR
#define DECL_IMPORT_VAR /* no DECL_IMPORT_VAR */
#endif
/* \code
     extern DECL_HIDE_VAR int global__;
   \endcode
 */
#ifndef DECL_HIDE_VAR
#define DECL_HIDE_VAR  /* no DECL_HIDE_VAR */
#endif
/* \code
     DECL_PRINTF(2,3)
     int my_printf(void* data, const char* fmt, ...);
   \endcode
 */
#ifndef DECL_PRINTF
#define DECL_PRINTF(a,b) /* no DECL_PRINTF(a,b) */
#endif
/* \code
     DECL_SCANF(2,3) 
     int my_scanf(void* data, const char* fmt, ...);
   \endcode
 */
#ifndef DECL_SCANF
#define DECL_SCANF(a,b) /* no DECL_SCANF(a,b) */
#endif
/* \code
     DECL_STRFTIME(3,4)
     size_t my_strftime(char* s, size_t sz
         , const char* fmt, const struct tm* tptr);
   \endcode
 */
#ifndef DECL_STRFTIME
#define DECL_STRFTIME(a,b) /* no DECL_STRFTIME(a,b) */
#endif
/* \code
     DECL_STRFMON(3,4)
     ssize_t my_strfmon(char* s, size_t sz, const char* fmt, ...);
   \endcode
 */
#ifndef DECL_STRFMON
#define DECL_STRFMON(a,b) /* no DECL_STRFMON(a,b) */
#endif
/* Get the inline keyword even when on C89 etc. Only if compiler supports it.

   \code
     static DECL_INLINE void f(x)
     { return x * 2; }
   \endcode
 */
#ifndef DECL_INLINE
#  if PLAT_CXX
#    define DECL_INLINE inline
#  else
#    define DECL_INLINE
#  endif
#endif

/* XXX find out if this is feasible.
 * could probably be done with -Werror on gcc using -std=whatever
 */
#if 0
/* Get the inline keyword only when the standard in use supports it.

   \sa DECL_INLINE

   \code
     static DECL_TRY_INLINE void f(x)
     { return x * 2; }
   \endcode
 */
#ifndef DECL_TRY_INLINE
#define DECL_TRY_INLINE
#endif
#endif //0

/* \code
     static DECL_INLINE DECL_FORCE_INLINE int square(int x) { return x*x; }
   \endcode

   \warn note how \c DECL_INLINE is still needed.
 */
#ifndef DECL_FORCE_INLINE
#define DECL_FORCE_INLINE    /* no DECL_FORCE_INLINE */
#endif
/* \code
     DECL_NEVER_INLINE int square(int x) { return x*x; }
   \endcode
 */
#ifndef DECL_NEVER_INLINE
#define DECL_NEVER_INLINE    /* no DECL_NEVER_INLINE */
#endif
/* Function has no effect except returning a value.
   The return value only depends on arguments and globals.
   This is a less strict version of DECL_CONST.
  
   \code
     DECL_PURE int times(int x);
   \endcode
   Then in foo.c
   \code
     int times(int x) { return x*global; }
   \endcode
 */
#ifndef DECL_PURE
#define DECL_PURE    /* no DECL_PURE */
#endif
/* Function has no effect except returning a value.
   The return value only depends on arguments and globals.
   This is a _more_ strict version of DECL_PURE.
  
   \code
     DECL_CONST int square(int x);
   \endcode
   Then in foo.c
   \code
     int square(int x) { return x*x; }
   \endcode
 */
#ifndef DECL_CONST
#define DECL_CONST   /* no DECL_CONST */
#endif
/* \code
     DECL_NORETURN void myabort(void);
   \endcode
   The in foo.c
   \code
     void myabort(void) { abort(); }
   \endcode
 */
#ifndef DECL_NORETURN
#define DECL_NORETURN    /* no DECL_NORETURN */
#endif
/* \code
     DECL_MALLOC char* mallocstring(void);
   \endcode
   The in foo.c
   \code
     char* mallocstring(void) { return malloc(10); }
   \endcode
 */
#ifndef DECL_MALLOC
#define DECL_MALLOC  /* no DECL_MALLOC */
#endif
/* Any non-NULL pointer returned cannot alias another pointer.
  
   \code
     DECL_CHECK_RESULT int inet_pton(const char* p, struct sockaddr* sa) { ... }
   \endcode
 */
#ifndef DECL_CHECK_RESULT
#define DECL_CHECK_RESULT    /* no DECL_CHECK_RESULT */
#endif
/* \code
     DECL_DEPRECATED void usleep(unsigned long usec) { ... }
   \endcode
 */
#ifndef DECL_DEPRECATED
#define DECL_DEPRECATED  /* no DECL_DEPRECATED */
#endif
/* \code
     DECL_USED void called_by_asm(void) { ... }
   \endcode
 */
#ifndef DECL_USED
#define DECL_USED    /* no DECL_USED */
#endif
/* \code
     int gettimeofday(struct timeval* tv, struct timezone* DECL_UNUSED tz) { ... }
   \endcode
 */
#ifndef DECL_UNUSED
#define DECL_UNUSED  /* no DECL_UNUSED */
#endif
/* \code
     if(DECL_LIKELY(decl_success())) { ... }
   \endcode
 */
#ifndef DECL_LIKELY
#define DECL_LIKELY
#endif
/* \code
     if(DECL_UNLIKELY(decl_error())) { ... }
   \endcode
 */
#ifndef DECL_UNLIKELY
#define DECL_UNLIKELY
#endif
#ifndef DECL_FUNCSIG
#define DECL_FUNCSIG "(unknown function signature)"
#endif
/*! \code
        DECL_ALIGN(AlignedVersionOfType, Type, 8);
    \endcode
 */
#ifndef DECL_ALIGN
#   if PLAT_CXX_0X && PLAT_HAVE_CXX_0X_ALIGN
#       define DECL_ALIGN(newtype, type, size) typedef [[ align(size) ]] type newtype
#   else
#       define DECL_ALIGN(newtype, type, size) typedef type newtype
#   endif
#endif

DECL_END_C
#endif /* DECL_CC_GENERIC_H_ */

