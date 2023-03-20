#include <stdio.h>

#ifndef LEN
#define LEN 9
#endif

const char s[] = "xxxx4xx10";

int main(void) {
  char ch;

  ch = 0x61;

  for (unsigned i = 0, j = 1; i < 9; ++i) {
    ch += j;
    j += 0xf;
    printf("0x%02x, ", s[i] == 0x78 ? ch & 0xff : s[i] & 0xff); 
  }

  putchar(0xa);

  return 0;
}
