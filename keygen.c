#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  char *user, *p, *buf, *p1, *s;
  uint64_t pass, x, y;
  unsigned len, i, j, k, a;

  srand(time(NULL));

  len = rand() % 0x15 + 5;

  if ((user = malloc(len + 1)) == NULL) {
    fprintf(stderr, "malloc failed");
    return EXIT_FAILURE;
  }


  for (i = 0; i < len; ++i) {
    user[i] = 0x61 + rand() % 0x1a;
  }

  user[len] = 0;

  puts(user);

  j = 0;
  k = 0;

  do {
    i = j + 1;
    i = ((i & 0xff) ^ 0x30) & 0xff;
    user[k] = ((user[k] & 0xff) + (i & 0xff)) & 0xff;
    i = 0xffffffff;
    ++j;
    k = j;
    do { ++i; } while (user[i]);
  } while (k < i);

  k = 0;
  i = 0xffffffff;

  do { ++i; } while (user[i]);

  j = 0;

  do {
    i = k & 0xff;
    i = (i & 0xff) & 0x10;
    user[j] = ((user[j] & 0xff) + (i & 0xff)) & 0xff;
    i = 0xffffffff;
    ++k;
    j = k;

    do { ++i; } while (user[i]);
  } while (j < i);

  j = 0;
  i = 0xffffffff;

  do { ++i; } while (user[i]);

  p = user;

  do {
    *p += 0x7e;
    p += 1;
    ++j;
    k = 0xffffffff;

    do { ++k; } while (user[k]);

    i = j;
  } while (i < k);

  j = 0xffffffff;

  do { ++j; } while (user[j]);

  if ((buf = malloc(j + 1)) == NULL) {
    fprintf(stderr, "malloc failed");
    free(user);
    return EXIT_FAILURE;
  }

  a = 0;
  p = user;
  p1 = buf;

  do {
    k = (*p & 0xff);
    p += 1;
    i = k & 0xff;
    ++a;
    i = ((i & 0xff) * 4) & 0xff;
    k = ((k & 0xff) + (i & 0xff)) & 0xff;
    i = a;
    *p1 = k & 0xff;
    ++p1;
  } while (i < j);

  *p1 = 0;

  if ((s = malloc(strlen(user) + strlen(buf) + 1)) == NULL) {
    fprintf(stderr, "malloc failed");
    free(user);
    free(buf);
    return EXIT_FAILURE;
  }

  memset(s, 0, strlen(user) + strlen(buf) + 1);
  memcpy(s, user, strlen(user));
  memcpy(s + strlen(user), buf, strlen(buf));

  x = 0; 
  p = s;
  j = 0;

  do {
    if ((*p >> 7) & 1) {
      i = 0xffffff00 | *p;
    }
    else {
      i = *p;
    }

    p += 1;
    k = j;
    k *= j;
    ++j;
    i += k;

    if (((i >> 0x1f) & 1)) {
      y = 0xffffffff00000000 | i;
    }
    else {
      y = i;
    }

    x += y;
    i = j;
  } while (i < strlen(s));

  y = x;
  y >>= 0x1e;
  y ^= x;
  y *= 0xbf58476d1ce4e5b9;
  x = y;
  x >>= 0x1b;
  x ^= y;
  x *= 0x94d049bb133111eb;
  y = x;
  y >>= 0x1f;
  y ^= x;
  pass = y;

  printf("%lu\n", pass);

  free(user);
  free(buf);
  free(s);

  return EXIT_SUCCESS;
}
