#include <stdio.h>

#ifndef LEN
#define LEN 8
#endif

int main(void) {
  int a[LEN];
  FILE *fd;

  if (!(fd = fopen("Simple CrackMe by Rainbow.exe", "rb"))) {
    fprintf(stderr, "error opening file\n");
    return 1;
  }

  fseek(fd, 0x822, SEEK_SET);

  for (unsigned i = 0; i < LEN; ++i) {
    fseek(fd, i > 1 ? 7 : 4, SEEK_CUR);
    fread(a + i, 4, 1, fd);
  }

  fclose(fd);

  puts((char *) a);

  return 0;
}
