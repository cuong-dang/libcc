#ifndef _FLOAT
#define _FLOAT
/* The following constants are taken from ISO/IEC 9899:1999. */

/* common */
#define FLT_RADIX 2
#define FLT_ROUNDS 1

/* float */
#define FLT_DIG 6
#define FLT_EPSILON 0X1P-23F
#define FLT_MANT_DIG 24
#define FLT_MAX 0X1.fffffeP127F
#define FLT_MAX_10_EXP (+38)
#define FLT_MAX_EXP (+128)
#define FLT_MIN 0X1P-126F
#define FLT_MIN_10_EXP (-37)
#define FLT_MIN_EXP (-125)

/* double */
#define DBL_DIG 15
#define DBL_EPSILON 0X1P-52
#define DBL_MANT_DIG 53
#define DBL_MAX 0X1.fffffffffffffP1023
#define DBL_MAX_10_EXP (+308)
#define DBL_MAX_EXP (+1024)
#define DBL_MIN 0X1P-1022
#define DBL_MIN_10_EXP (-307)
#define DBL_MIN_EXP (-1021)

#endif
