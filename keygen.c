#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LEN
#define LEN 7
#endif

int main(void) {
  char user[LEN+1];
  int ch;

  srand(time(NULL));

  for (size_t i = 0; i < LEN; ++i)
    user[i] = 97 + rand() % 26;

  user[LEN] = 0;

  puts(user);

  for (size_t i = 0; i < LEN; ++i) {
    ch = ((user[i] ^ LEN) * LEN) ^ user[i];

    putchar(ch / 100 + 48); 
    putchar(ch / 10 % 10 + 48);
    putchar(ch % 10 + 48);
  }

  putchar(0xa);

  return EXIT_SUCCESS;
}
