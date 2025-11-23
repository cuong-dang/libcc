#ifndef _FLOAT
#define _FLOAT
/* An implementation following IEEE 754. */

/* Varying across platforms */
#define _DBIAS 0x3fe
#define _DLONG 1
#define _DOFF 4
#define _FBIAS 0x7e
#define _FOFF 7
#define _FRND 1
#define _LBIAS 0x3ffe
#define _LOFF 15

/* Implementation */
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

#endif
