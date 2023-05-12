#include <stdio.h>
#include <string.h>

#ifndef LEN
#define LEN 26
#endif

int main(void) {
  char key[LEN+1];
  int a[LEN];
  FILE *fd;

  fd = fopen("crackme.exe", "rb");
  if (!fd) return 1;

  fseek(fd, 0x56c, SEEK_SET);
  fread(key + 16, 4, 1, fd);

  fseek(fd, 3, SEEK_CUR);
  fread(key + 20, 4, 1, fd);

  fseek(fd, 4, SEEK_CUR);
  fread(key + 24, 2, 1, fd);

  fseek(fd, 0x15f3, SEEK_CUR);
  fread(key, 1, 16, fd);

  fclose(fd);

  key[LEN] = 0;

  puts(key);

  memset(a, 0, sizeof(int) * LEN);

  for (int i = 0; i < LEN; ++i) {
    ++a[key[i] - 65];
  }

  for (int i = 0; i < LEN; ++i) {
    if (a[i] != 1) {
      printf("%c\n", 65 + i);
    }
  }

  return 0;
}
