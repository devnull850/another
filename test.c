#include <stdio.h>

#ifndef LEN
#define LEN 0x10
#endif

const unsigned a[] = { 0xdd2e8c56, 0xd52b285c, 0x11cc6569, 0x5294c4b8 };
const unsigned b[] = { 0xb641e105, 0x9c4c4635, 0x7ea3261a, 0x5294c4d4 };

int main(void) {
  for (unsigned i = 0; i < LEN; ++i) {
    putchar(*(((char *)a)+i) ^ *(((char *)b)+i));
  }

  putchar(0xa);

  return 0;
}
