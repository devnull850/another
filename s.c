#include <stdio.h>
#include <string.h>

#ifndef LEN
#define LEN 62
#endif

const char CHARSET[] = "0123456789ABCDEFGHIJKLMNOPQRSTU"
                       "VWXYZabcdefghijklmnopqrstuvwxyz";

int main(void) {
  char s[LEN+1];
  int a[LEN];
  FILE *fd;

  fd = fopen("crackme.exe", "rb");
  if (!fd) return 1;

  fseek(fd, 0x532, SEEK_SET);
  fread(s + 48, 4, 1, fd);

  fseek(fd, 16, SEEK_CUR);
  fread(s + 52, 4, 1, fd);

  fseek(fd, 16, SEEK_CUR);
  fread(s + 56, 4, 1, fd);

  fseek(fd, 9, SEEK_CUR);
  fread(s + 60, 2, 1, fd);

  fseek(fd, 0x15f7, SEEK_CUR);
  fread(s + 32, 1, 16, fd);

  fseek(fd, 16, SEEK_CUR);
  fread(s, 1, 16, fd);
  fread(s + 16, 1, 16, fd);

  fclose(fd);

  s[LEN] = 0;

  puts(s);

  memset(a, 0, sizeof(int) * LEN);

  for (int i = 0; i < LEN; ++i) {
    if (s[i] >= 48 && s[i] < 58) {
      ++a[s[i] - 48];
    }
    else if (s[i] >= 65 && s[i] < 91) {
      ++a[s[i] - 55];
    }
    else if (s[i] >= 97 && s[i] < 123) {
      ++a[s[i] - 61];
    }
  }

  for (int i = 0; i < LEN; ++i) {
    if (a[i] != 1) {
      printf("%c\n", CHARSET[i]);
    }
  }

  return 0;
}
