#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef LEN
#define LEN 14
#endif

const char SET[] = "0123456789ABCDEFGHIJKLMNOPQRSTU"
                   "VWXYZabcdefghijklmnopqrstuvwxyz";
const unsigned SET_LEN = 62;

int main(void) {
    char flag[LEN+1];
    int n, tmp;

    srand(time(NULL));

    flag[10] = SET[rand() % SET_LEN];

    while (1) {
        n = 0;

        do {
            flag[0] = SET[rand() % SET_LEN];
            flag[2] = SET[rand() % SET_LEN];
            flag[3] = SET[rand() % SET_LEN];
            flag[4] = SET[rand() % SET_LEN];
            flag[5] = SET[rand() % SET_LEN];
            flag[6] = SET[rand() % SET_LEN];
            flag[8] = SET[rand() % SET_LEN];
            flag[9] = SET[rand() % SET_LEN];

            n = flag[2] - flag[8] * flag[8] * flag[9] *
                flag[3] * flag[4] * flag[5] * flag[6] *
                flag[0] * flag[2];
        } while (n < 601 || n > 932066);

        tmp = n;

        do {
            n = tmp;

            flag[1] = SET[rand() % SET_LEN];
            flag[7] = SET[rand() % SET_LEN];

            n = n * flag[1] * flag[0] + flag[7] + flag[7];
        } while (n < 8957952);

        tmp = n;

        do {
            n = tmp;

            flag[11] = SET[rand() % SET_LEN];
            flag[12] = SET[rand() % SET_LEN];
            flag[13] = SET[rand() % SET_LEN];

            n = n / flag[11] / flag[12] / flag[13];
        } while (n < 81 || n > 1347);

        n = flag[1] * flag[0] * flag[2] * n - 148000000;

        if (n >= 0 && n < 1000000) {
            break;
        }
    }

    flag[LEN] = 0;

    puts(flag);

    return EXIT_SUCCESS;
}