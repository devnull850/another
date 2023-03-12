#include <stdio.h>

#ifndef LEN
#define LEN 0x1a
#endif

int main(void) {
  unsigned a[5];
  char s[LEN + 1];
  FILE *fd;

  fd = fopen("BabyRE", "rb");

  fseek(fd, 0x1aae0, SEEK_SET);
  fread(s, 1, 0x10, fd);

  fseek(fd, 0x4a6, SEEK_SET);
  fread(s + 0x10, 4, 1, fd);

  fseek(fd, 3, SEEK_CUR);
  fread(s + 0x14, 4, 1, fd);

  fseek(fd, 4, SEEK_CUR);
  fread(s + 0x18, 2, 1, fd);

  fclose(fd);

  s[0x1a] = 0;

#ifdef DEBUG
  puts(s);
#endif

  for (unsigned i = 0; i < LEN; ++i) {
    if (i < 5) {
      a[i] = (s[i] ^ "flag{"[i]) & 0xff;
    }

    putchar((s[i] ^ a[i % 5]) & 0xff);
  }

  putchar(0xa);

#ifdef DEBUG
  for (unsigned i = 0; i < 5; ++i)
    printf("0x%0x\n", a[i]);
#endif

  return 0;
}
