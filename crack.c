#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LEN
#define LEN 20
#endif

const char SET[] = "0123456789ABCDEFGHIJKLMNOPQRSTU"
                   "VWXYZabcdefghijklmnopqrstuvwxyz";
const unsigned SET_LEN = 62;

int main(void) {
  char name[LEN+1];
  int serial;
  unsigned length;

  srand(time(NULL));

  length = rand() % 16 + 5;

  for (size_t i = 0; i < length; ++i) {
    name[i] = SET[rand() % SET_LEN];
    serial += name[i];
  }

  name[length] = 0;

  printf("%s\n%d\n", name, (7 ^ (1176 * (serial ^ 6))) * 58800);

  return EXIT_SUCCESS;
}
