#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LEN
#define LEN 16
#endif

const char s[] = "DYo15z9atB8gZJRhpi0dLfCSA3wVFEy"
                 "uHKOrTWG4mlXvPeU2j67NbMxsknQqcI";
const char key[] = "EYIPVMTKFXJSGWQOADRNCBLHZU";
const char set[] = "0123456789ABCDEFGHIJKLMNOPQRSTU"
                   "VWXYZabcdefghijklmnopqrstuvwxyz";

int main(void) {
  char name[LEN+1], id[LEN+1];
  char *p;

  srand(time(NULL));

  for (size_t i = 0; i < LEN; ++i) {
    name[i] = set[rand() % 52 + 10];
  }

  name[LEN] = 0;

  p = id + 2;

  for (int i = 2, j, k = 0; i - 2 < 16; i += 4, k += 5348) {
    for (j = 0; j < 62; ++j) {
      if (s[j] == name[(i - 2) % LEN]) break;
    }

    j = 65536 * (k + j);
    if (((j >> 31) & 1)) {
      j ^= 0xffffffff;
      j -= 0xffffffff;
    }

    *(p - 2) = key[j % 26];

    for (j = 0; j < 62; ++j) {
      if (s[j] == name[(i - 1) % LEN]) break;
    }

    j += 1337;
    j += k;
    j *= 65536;
    if (((j >> 31) & 1)) {
      j ^= 0xffffffff;
      j -= 0xffffffff;
    }

    *(p - 1) = key[j % 26];

    for (j = 0; j < 62; ++j) {
      if (s[j] == name[i % LEN]) break;
    }

    j += 2674;
    j += k;
    j *= 65536;
    if (((j >> 31) & 1)) {
      j ^= 0xffffffff;
      j -= 0xffffffff;
    }

    *p = key[j % 26];

    for (j = 0; j < 62; ++j) {
      if (s[j] == name[(i + 1) % LEN]) break;
    }

    j += 4011;
    j += k;
    j *= 65536;
    if (((j >> 31) & 1)) {
      j ^= 0xffffffff;
      j -= 0xffffffff;
    }

    *(p + 1) = key[j % 26];

    p += 4;
  }

  id[LEN] = 0;

  printf("%s\n%s\n", name, id);

  return 0;
}
