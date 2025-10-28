#include <stdlib.h>

#include "cc/std/assert.h"
#include "cc/std/ctype.h"

#include "test_utils.h"

typedef int (*fnptr_t)(int);

void runner(const char *s, fnptr_t const *fs, int fs_size, fnptr_t const *nfs,
            int nfs_size);

void test_isupper_class() {
  fnptr_t fs[] = {isupper, isalpha};
  fnptr_t nfs[] = {islower, isdigit};

  runner("ABCDEFGHIJKLMNOPQRSTUVWXYZ", fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
}

void test_islower_class() {
  fnptr_t fs[] = {islower, isalpha};
  fnptr_t nfs[] = {isupper, isdigit};

  runner("abcdefghijklmnopqrstuvwxyz", fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
}

void test_isdigit_class() {
  fnptr_t fs[] = {isdigit};
  fnptr_t nfs[] = {isupper, islower, isalpha};

  runner("1234567890", fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
}

int main(void) {
  test_isupper_class();
  test_islower_class();
  return EXIT_SUCCESS;
}

void runner(const char *s, fnptr_t const *fs, int fs_size, fnptr_t const *nfs,
            int nfs_size) {
  const char *t;
  int i;

  for (t = s; *t; ++t) {
    for (i = 0; i < fs_size; ++i) {
      assert(fs[i](*t));
    }
    for (i = 0; i < nfs_size; ++i) {
      assert(!nfs[i](*t));
    }
  }
}
