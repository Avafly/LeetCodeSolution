#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

char * intToRoman(int num) {
    char *ans = (char *)calloc(SIZE, sizeof(char));
    int ansSize = 0;

    while(num > 0) {
        if (num >= 1000) {
            num -= 1000;
            ans[ansSize++] = 'M';
        }
        else if (num >= 900) {
            num -= 900;
            ans[ansSize++] = 'C';
            ans[ansSize++] = 'M';
        }
        else if (num >= 500) {
            num -= 500;
            ans[ansSize++] = 'D';
        }
        else if (num >= 400) {
            num -= 400;
            ans[ansSize++] = 'C';
            ans[ansSize++] = 'D';
        }
        else if (num >= 100) {
            num -= 100;
            ans[ansSize++] = 'C';
        }
        else if (num >= 90) {
            num -= 90;
            ans[ansSize++] = 'X';
            ans[ansSize++] = 'C';
        }
        else if (num >= 50) {
            num -= 50;
            ans[ansSize++] = 'L';
        }
        else if (num >= 40) {
            num -= 40;
            ans[ansSize++] = 'X';
            ans[ansSize++] = 'L';
        }
        else if (num >= 10) {
            num -= 10;
            ans[ansSize++] = 'X';
        }
        else if (num >= 9) {
            num -= 9;
            ans[ansSize++] = 'I';
            ans[ansSize++] = 'X';
        }
        else if (num >= 5) {
            num -= 5;
            ans[ansSize++] = 'V';
        }
        else if (num >= 4) {
            num -= 4;
            ans[ansSize++] = 'I';
            ans[ansSize++] = 'V';
        }
        else if (num >= 1) {
            num -= 1;
            ans[ansSize++] = 'I';
        }
    }
    return ans;
}

int main(int argc, char **argv) {
    int num = 3888;

    char *ans = intToRoman(num);
    printf("%s\n", ans);
    free(ans);

    return 0;
}
