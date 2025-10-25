#include <stdlib.h>

#define NDEBUG
#include "cc/std/assert.h"

static int val = 0;

void handle_abort(int sig) {
  if (val == 1) {
    exit(EXIT_SUCCESS);
  }
  exit(EXIT_FAILURE);
}

void dummy(void) {
  assert(0 == 0);
  assert(0 == 1);
}

#undef NDEBUG
#include "cc/std/assert.h"

int main(void) {
  signal(SIGABRT, &handle_abort);

  dummy();          /* nothing should happen */
  assert(val == 0); /* should not abort */
  ++val;
  assert(val == 0); /* should jump to handle_abort */
  return EXIT_FAILURE;
}
