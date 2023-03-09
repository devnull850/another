#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LEN
#define LEN 0xd
#endif

void fill_array(int *, int, int);
int sum_array(int *, int, int);

int main(void) {
  int a[LEN], x, y, z;

  srand(time(NULL));

  fill_array(a, 0, 3);
  x = sum_array(a, 0, 3);
  x %= 3;

  for (int i = 4, j = 0; i < LEN; ++j) {
    fill_array(a, i, i + 3);
    y = sum_array(a, i, i + 3);
    z = x ^ a[(i - 4) / 3];

    if (z == y % 9) {
        i += 3;
        j = -1;
    }

    if (j == 0xa) {
      srand(time(NULL));
    }
  }

  for (size_t i = 0; i < LEN; ++i) {
    putchar(i != 3 ? a[i] + 0x30 : 0x2d);
  }

  putchar(0xa);

  return EXIT_SUCCESS;
}

void fill_array(int *a, int x, int y) {
  for (int i = x; i < y; ++i) {
    a[i] = rand() % 0xa;
  }
}

int sum_array(int *a, int x, int y) {
  int sum = 0;

  for (int i = x; i < y; ++i) {
    sum += a[i];
  }

  return sum;
}

