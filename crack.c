#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LEN
#define LEN 19
#endif

int main(void) {
  char s[LEN+1];

  srand(time(NULL));

  s[0] = 0x47;
  s[18] = 0x47;

  s[4] = rand() % 2 ? 65 : 97;
  s[4] = s[4] + rand() % 26;
  s[1] = rand() % 2 && s[4] < 123 ? s[4] + 5 : s[4] - 5;
  s[2] = rand() % 2 && s[1] < 123 ? s[1] + 5 : s[1] - 5;
  s[3] = rand() % 2 && s[2] < 123 ? s[2] + 5 : s[2] - 5;

  s[5] = rand() % 2 ? 65 : 97;
  s[5] = s[5] + rand() % 26;
  s[6] = rand() % 2 && s[5] < 123 ? s[5] + 5 : s[5] - 5;
  s[7] = rand() % 2 && s[6] < 123 ? s[6] + 5 : s[6] - 5;
  s[8] = rand() % 2 && s[7] < 123 ? s[7] + 5 : s[7] - 5;

  s[9] = rand() % 2 ? 65 : 97;
  s[9] = s[9] + rand() % 26;

  s[10] = rand() % 2 ? 65 : 97;
  s[10] = s[10] + rand() % 26;
  s[11] = rand() % 2 && s[10] < 123 ? s[10] + 5 : s[10] - 5;
  s[12] = rand() % 2 && s[11] < 123 ? s[11] + 5 : s[11] - 5;
  s[13] = rand() % 2 && s[12] < 123 ? s[12] + 5 : s[12] - 5;

  s[15] = rand() % 2 ? 65 : 97;
  s[15] = s[15] + rand() % 26;
  s[16] = rand() % 2 && s[15] < 123 ? s[15] + 5 : s[15] - 5;
  s[17] = rand() % 2 && s[16] < 123 ? s[16] + 5 : s[16] - 5;
  s[14] = rand() % 2 && s[17] < 123 ? s[17] + 5 : s[17] - 5;

  s[LEN] = 0;

  puts(s);

  return EXIT_SUCCESS;
}
