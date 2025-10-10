#include <stdio.h>
#include <stdlib.h>

#include "cc/std/assert.h"

void _assert(char *msg) {
  fputs(msg, stderr);
  abort();
}
