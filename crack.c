#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LEN
#define LEN 16
#endif

int generate_char(int);

int main(void) {
  unsigned n, x, y;
  char key[LEN+1];

  srand(time(NULL));

  n = rand() % 6 + 4;
  key[0] = n * 10 + 2;

  key[1] = generate_char(1);

  n = rand() % 6 + 4;
  key[2] = n * 10 + 9;

  n = rand() % 6 + 4;
  key[3] = n * 10 + 7;

  n = rand() % 6 + 4;
  key[4] = 10 * n;

  n = rand() % 6 + 4;
  key[5] = n * 10 + 6;

  n = rand() % 6 + 4;
  key[6] = 10 * n + 6;

  key[7] = generate_char(0);

  key[8] = generate_char(1);

  key[9] = generate_char(0);

  n = rand() % 3;
  x = n;
  y = 2 - n;

  if (n < 2) {
    key[10] = 100 + y * 10 + x;
  }
  else {
    n = rand() % 6 + 4;
    key[10] = n * 10;
  }

  key[11] = 100;

  n = rand() % 3;
  x = n;
  y = 2 - n;

  if (n < 2) {
    key[12] = 100 + y * 10 + x;
  }
  else {
    n = rand() % 6 + 4;
    key[12] = n * 10;
  }

  n = rand() % 6 + 4;
  key[13] = n * 10 + 8;

  n = rand() % 6 + 4;
  key[14] = n * 10 + 8;

  n = rand() % 6 + 4;
  key[15] = n * 10 + 9;

  key[LEN] = 0;

  puts(key);

  return EXIT_SUCCESS;
}

int generate_char(int n) {
  int r;

  r = rand() % 2;

  if ((r & 1) == 0) {
    r = rand() % 3;
    return 100 + n * 10 + r;
  }

  r = rand() % 6 + 4;
  return r * 10 + n;
}
