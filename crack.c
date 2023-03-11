#include <stdio.h>

#ifndef LEN
#define LEN 0x20
#endif

int main(void) {
  char pass[LEN+1];
  int a[0x10];
  FILE *fd;

  fd = fopen("VMAdventures1-Crackme.exe", "rb");

  fseek(fd, 0x22d0, SEEK_SET);

  for (unsigned i = 0; i < 0x10; ++i)
    a[i] = fgetc(fd);

  fread(pass, 1, LEN, fd);

  fclose(fd);

  pass[LEN] = 0;

  for (int i = 0xf; i >= 0; --i) {
    switch (a[i]) {
      case 1:
        for (unsigned j = 0; j < LEN; ++j)
          pass[j] ^= 0x54;

        break;

      case 2:
        for (unsigned j = 0; j < LEN; ++j)
          pass[j] ^= 0x24;

        break;

      case 3:
        for (unsigned j = 0; j < LEN; ++j)
          pass[j] = ((pass[j] & 3) << 6)  | ((pass[j] >> 2) & 0x3f);

        break;

      case 4:
        for (unsigned j = 0; j < LEN; ++j)
          pass[j] -= 0xeb;

        break;
    }
  }

  puts(pass);

  return 0;
}
