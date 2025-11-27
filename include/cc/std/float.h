#ifndef _FLOAT
#define _FLOAT
/* An implementation following IEEE 754. */

typedef struct {
  int dig, mant_dig, max10e, maxe, min10e, mine;
  union {
    unsigned short us[5];
    float f;
    double d;
    long double ld;
  } eps, max, min;
} _Dvals;

extern _Dvals _Dbl, _Flt, _Ldbl;

/* double */
#define DBL_DIG _Dbl.dig;
#define DBL_EPSILON _Dbl.eps.d;
#define DBL_MANT_DIG _Dbl.mant_dig;
#define DBL_MAX _Dbl.max.d;
#define DBL_MAX_10_EXP _Dbl.max10e;
#define DBL_MAX_EXP _Dbl.maxe;
#define DBL_MIN _Dbl.min.d;
#define DBL_MIN_10_EXP _Dbl.min10e;
#define DBL_MIN_EXP _Dbl.mine;

#endif
