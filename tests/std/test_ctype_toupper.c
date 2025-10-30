#include <stdlib.h>
#include <string.h>

#include "cc/std/assert.h"
#include "cc/std/ctype.h"

int main(void) {
  char *in = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  size_t len = strlen(in);
  int i;

  for (i = 0; i < len; ++i) {
    assert(toupper(in[i]) == expected[i]);
  }
  return EXIT_SUCCESS;
}
