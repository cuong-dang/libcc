#include "cc/std/assert.h"
#include <stdio.h>
#include <stdlib.h>

void _assert(const char *msg) {
  fputs(msg, stderr);
  abort();
}
