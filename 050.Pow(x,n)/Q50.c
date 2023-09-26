
// LeetCode Problem:
// Title: Pow(x, n)
// URL: https://leetcode.com/problems/powx-n/

#include <stdio.h>

double myPow(double x, int n){
    if(n == 0) {
        return 1.0;
    }

    double ans = 1.0;
    long long power = n;

    if(n < 0) {
        x = 1 / x;
        power = -((long)n);
    }

    while(power > 0) {
        if(power % 2 == 1) {
            ans *= x;
        }
        x *= x;
        power /= 2;
    }

    return ans;
}

int main(int argc, char **argv) {
    double x = 1.5;
    int n = 15;
    printf("%f\n", myPow(x, n));

    return 0;
}