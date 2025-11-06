#include "cc/std/assert.h"
#include "cc/std/errno.h"

int main(void) {
  errno = 0;
  assert(errno == 0);
  errno = EDOM;
  assert(errno == EDOM);
}
