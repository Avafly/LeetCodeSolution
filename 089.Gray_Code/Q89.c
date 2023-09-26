
// LeetCode Problem:
// Title: Gray Code
// URL: https://leetcode.com/problems/gray-code/

#include <stdio.h>
#include <stdlib.h>

/*
 Gray code = Binary number XOR (Binary number >> 1)
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int *returnSize){
    int size = 1 << n;
    *returnSize = size;
    int *ans = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < size; ++i) {
        ans[i] = i ^ (i >> 1);
    }
    return ans;
}

int main(int argc, char **argv) {
    int n = 5;
    int returnSize;
    
    int *ans = grayCode(n, &returnSize);
    for(int i = 0; i < returnSize; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    free(ans);
    
    return 0;
}
