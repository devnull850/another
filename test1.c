#include <stdio.h>

#ifndef LEN
#define LEN 0x20
#endif

const unsigned a[] = { 0xde0eeb0f, 0xbc232815, 0xac24e6e, 0x3cfda5f4,
                       0x6f1a04f3, 0xdc92b05, 0x16b53968, 0x46e026fe };
const unsigned b[] = { 0xb641e105, 0x9c4c4635, 0x7ea3261a, 0x5294c4d4,
                       0x792487, 0x6eac5977, 0x16b5171c, 0x46e026fe };

int main(void) {
  for (unsigned i = 0; i < LEN; ++i) {
    putchar(*(((char *)a)+i) ^ *(((char *)b)+i));
  }

  putchar(0xa);

  return 0;
}
