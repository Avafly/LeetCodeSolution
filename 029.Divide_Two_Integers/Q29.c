#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor){

    if(dividend == 0) return 0;

    long ans = 0;
    long dd = dividend;
    long dr = divisor;

    int neg = (dd>0) ^ (dr>0);

    dd = labs(dd);
    dr = labs(dr);

    if(dr == 1) {
        ans = dd;
    }
    else {
        for(int i=31; i>=0; --i) {
            if(dr<<i <= dd) {
                dd -= dr << i;
                ans += 1 << i;
            }
        }
    }
    ans = neg ? -ans : ans;

    if(ans > 2147483647) return 2147483647;
    if(ans < -2147483648) return -2147483648;
    return ans;
}

int test(int dividend, int divisor) {
    long ans = (long)dividend / (long)divisor;

    if(ans > 2147483647) return 2147483647;
    if(ans < -2147483648) return -2147483648;
    return ans;
}

int main(int argc, char **argv) {
    int dividend = 15;
    int divisor = 2;

    printf("Solution:\t%d\n", test(dividend, divisor));
    printf("Ans:\t\t%d\n", divide(dividend, divisor));

    return 0;
}