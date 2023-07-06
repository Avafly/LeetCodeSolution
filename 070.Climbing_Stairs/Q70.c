#include <stdio.h>

/*
 * Idea: suppose n(k) is the number of distinct ways that can climb to k-th step,
 * thus n(k) = n(k - 1) + n(k - 2)
 */

int climbStairs(int n){
    if(n < 1)       return 0;
    else if(n <= 3) return n;

    int prev = 2;
    int curr = 3;
    int temp;
    for(int i = 4; i <= n; ++i) {
        temp = curr;
        curr += prev;
        prev = temp;
    }

    return curr;
}

int main(int argc, char **argv) {
    for(int i = 1; i <= 15; ++i) {
        printf("%d\n", climbStairs(i));
    }
    return 0;
}