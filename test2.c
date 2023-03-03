/* FUN_004014d0 */

#include <stdio.h>

// local_160
const unsigned a[] = { 0xd902eb0f, 0xfd3e215b, 0x783556e, 0x21b4b1bb,
                       0x681c49e8, 0x38c2e18, 0x71d4797d, 0x32c0429b };
// local_140
const unsigned b[] = { 0xe41cae66, 0xfed6d089, 0xf764beee, 0x727b1a18,
                       0x760c67e8, 0x1aff461b, 0x75a63d21, 0x4964ade5 };
// local_120
const unsigned c[] = { 0x92feefbe, 0x7b48748d, 0x530abe26, 0xbd4a540c };
// local_a0
const unsigned d[] = { 0xb641e105, 0x9c4c4635, 0x7ea3261a, 0x5294c4d4,
                       0x792487, 0x6eac5977, 0x16b5171c, 0x46e026fe };
// local_80
const unsigned e[] = { 0x9d7e8e09, 0x8da5b1f9, 0x920ccace, 0x17135938,
                       0x5a7f0c8b, 0x3a90213b, 0x55c25340, 0x6910c882 };
// local_60
const unsigned f[] = { 0xf79380cd, 0x152936ad, 0x5324c742, 0xbd4a540c };

int main(void) {
  for (unsigned i = 0; i < 0x20; ++i) {
    putchar(*(((char *)a)+i) ^ *(((char *)d)+i));
  }

  for (unsigned i = 0; i < 0x20; ++i) {
    putchar(*(((char *)b)+i) ^ *(((char *)e)+i));
  }

  for (unsigned i = 0; i < 0x10; ++i) {
    putchar(*(((char *)c)+i) ^ *(((char *)f)+i));
  }

  putchar(0xa);

  return 0;
}
