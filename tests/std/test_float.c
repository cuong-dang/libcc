#include "cc/std/assert.h"
#include "cc/std/float.h"

#include <math.h>
#include <stdio.h>

int main(void) {
  double radlog = log10(FLT_RADIX);
  int digs = (DBL_MANT_DIG - 1) * radlog;

  assert(10 <= DBL_DIG);
  assert(DBL_EPSILON <= 1e-9);
  assert(digs <= DBL_DIG && DBL_DIG <= digs + 1);
  printf("%le\n", DBL_MAX);
  assert(1e37 <= DBL_MAX);
  assert(37 <= DBL_MAX_10_EXP);
}
