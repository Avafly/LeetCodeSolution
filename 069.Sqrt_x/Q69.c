
// LeetCode Problem:
// Title: Sqrt(x)
// URL: https://leetcode.com/problems/sqrtx/

#include <stdio.h>

// binary search
int mySqrt(int x){
    if(x == 1)  return 1;

    long l = 0;
    long r = x;
    while(l < r) {
        long mid = (l + r) / 2;
        if(mid * mid > x) {
            r = mid;
        }
        else {
            l = mid;
        }
        // r - l == 1 means l < sqrt(x) < r
        if(r - l == 1) {
            break;
        }
    }
    return l;
}

int main(int argc, char **argv) {
    int x = 0;
    printf("%d\n", mySqrt(x));
    return 0;
}