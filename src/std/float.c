#include "cc/std/float.h"

/* Varying across platforms */
#define DBIAS 0x3fe
#define DLONG 1
#define DOFF 4
#define FBIAS 0x7e
#define FOFF 7
#define FRND 1
#define LBIAS 0x3ffe
#define LOFF 15

#define FFRAC (17 + FOFF)
#define FMAXE ((1U << (15 - FOFF)) - 1)
#define DFRAC (49 + DOFF)
#define DMAXE ((1U << (15 - DOFF)) - 1)
#define LFRAC (49 + LOFF)
#define LMAXE 0x7fff
#define LOG2 0.30103

/* Init by words */
#define FINIT(w0, wx) w0, wx
#define DINIT(w0, wx) w0, wx, wx, wx
#define LINIT(w0, w1, wx) w0, w1, wx, wx, wx

_Dvals _Dbl = {
    (int)((DFRAC - 1) * LOG2) /* DBL_DIG */, (int)DFRAC, /* DBL_MANT_DIG */(int)((DMAXE - DBIAS - 1) * LOG2),                   /* DBL_MAX_10_EXP */
};
