#include "cc/std/assert.h"
#include "cc/std/ctype.h"

#include "test_utils.h"

typedef int (*fnptr_t)(int);

#include <stdlib.h>

void run(const char *s, fnptr_t const *fs, int fs_size, fnptr_t const *nfs,
         int nfs_size);

void test_isupper() {
  fnptr_t fs[] = {isupper, isalpha, isalnum, isgraph, isprint};
  fnptr_t nfs[] = {islower, isdigit, ispunct, isspace, iscntrl};
  fnptr_t isxdigit_[] = {isxdigit};

  run("ABCDEFGHIJKLMNOPQRSTUVWXYZ", fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
  run("ABCDEF", isxdigit_, ARRAY_LEN(isxdigit_), NULL, 0);
  run("GHIJKLMNOPQRSTUVWXYZ", NULL, 0, isxdigit_, ARRAY_LEN(isxdigit_));
}

void test_islower() {
  fnptr_t fs[] = {islower, isalpha, isalnum, isgraph, isprint};
  fnptr_t nfs[] = {isupper, isdigit, ispunct, isspace, iscntrl};
  fnptr_t isxdigit_[] = {isxdigit};

  run("abcdefghijklmnopqrstuvwxyz", fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
  run("abcdef", isxdigit_, ARRAY_LEN(isxdigit_), NULL, 0);
  run("ghijklmnopqrstuvwxyz", NULL, 0, isxdigit_, ARRAY_LEN(isxdigit_));
}

void test_isdigit() {
  fnptr_t fs[] = {isdigit, isxdigit, isalnum, isgraph, isprint};
  fnptr_t nfs[] = {isupper, islower, isalpha, ispunct, isspace, iscntrl};

  run("1234567890", fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
}

void test_ispunct() {
  fnptr_t fs[] = {ispunct, isgraph, isprint};
  fnptr_t nfs[] = {isxdigit, isalnum, isdigit, isalpha,
                   isupper,  islower, isspace, iscntrl};

  run("!\"#$%&;()*+-./:;<=>?@[\\]^_`", fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
}

void test_sp() {
  fnptr_t fs[] = {isprint, isspace};
  fnptr_t nfs[] = {isgraph, isxdigit, isalnum, ispunct, isdigit,
                   isalpha, isupper,  islower, iscntrl};

  run(" ", fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
}

void test_cs() {
  fnptr_t fs[] = {isspace, iscntrl};
  fnptr_t nfs[] = {isprint, isgraph, isxdigit, isalnum, ispunct,
                   isdigit, isalpha, isupper,  islower};
  char cs[] = {9, 10, 11, 12, 13, 0};

  run(cs, fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
}

void test_bb() {
  fnptr_t fs[] = {iscntrl};
  fnptr_t nfs[] = {isprint, isspace, isgraph, isxdigit, isalnum,
                   ispunct, isdigit, isalpha, isupper,  islower};
  char bb[] = {7, 8, 0};

  run(bb, fs, ARRAY_LEN(fs), nfs, ARRAY_LEN(nfs));
}

int main(void) {
  test_isupper();
  test_islower();
  test_isdigit();
  test_ispunct();
  test_sp();
  test_cs();
  test_bb();
  return EXIT_SUCCESS;
}

void run(const char *s, fnptr_t const *fs, int fs_size, fnptr_t const *nfs,
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
