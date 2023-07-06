#include <stdio.h>

int reverse(int x){
    if (x > -10 && x < 10) {
        return x;
    }

    long rev = 0;
    while (x != 0) {
        rev *= 10;
        rev += x % 10;
        // check rev value
        if (rev > 2147483647 || rev < -2147483648) {
            return 0;
        }
        x /= 10;
    }

    return rev;
}

int main(int argc, char** argv) {
    printf("%d\n", reverse(-123));

    return 0;
}
