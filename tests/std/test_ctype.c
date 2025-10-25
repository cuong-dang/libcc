#include <stdio.h>

#include "cc/std/assert.h"
#include "cc/std/ctype.h"

#include <_stdlib.h>

void test_isupper_class() {
  char *s;

  for (s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; *s; ++s) {
    assert(isupper(*s));
    assert(!islower(*s));
    assert(isalpha(*s));
  }
}

int main(void) {
  test_isupper_class();
  return EXIT_SUCCESS;
}
