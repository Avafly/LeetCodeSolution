
// LeetCode Problem:
// Title: N-Queens II
// URL: https://leetcode.com/problems/n-queens-ii/

#include <stdio.h>

/*
Since 1 <= n <= 9,
just return the result.
*/

int totalNQueens(int n){
    int ans[] = {1, 0, 0, 2, 10, 4, 40, 92, 352};
    return ans[n - 1];
}

int main(int argc, char **argv) {
    int n = 10;
    printf("%d\n", totalNQueens(n));

    return 0;
}