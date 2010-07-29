#ifndef DECL_C_H_
#define DECL_C_H_

#ifdef __cplusplus
#  define DECL_BEGIN_C extern "C" {
#  define DECL_END_C   }
#else
#  define DECL_BEGIN_C
#  define DECL_END_C
#endif

#endif /* DECL_C_H_ */

