#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;
    for (unsigned int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

unsigned long long combinationSize(unsigned int n, unsigned int r) {
    unsigned long long n_fact = factorial(n);
    unsigned long long r_fact = factorial(r);
    unsigned long long n_r_fact = factorial(n - r);
    return n_fact / (r_fact * n_r_fact);
}

void rec(int **ans, int *ansSize, int *nums, int *numsSize, int n, int k, int start) {
    if(*numsSize == k) {
        ans[*ansSize] = (int *)malloc(sizeof(int) * k);
        memcpy(ans[(*ansSize)++], nums, sizeof(int) * k);
        return;
    }
    for(int i = start; i <= n; ++i) {
        nums[(*numsSize)++] = i;
        rec(ans, ansSize, nums, numsSize, n, k, i + 1);
        --(*numsSize);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    *returnSize = (int)combinationSize(n, k);
    *returnColumnSizes = (int *)calloc(*returnSize, sizeof(int));
    int **ans = (int **)calloc(*returnSize, sizeof(int *));
    int *ansSize = (int *)calloc(1, sizeof(int));
    int *nums = (int *)calloc(k, sizeof(int));
    int *numsSize = (int *)calloc(1, sizeof(int));
    
    rec(ans, ansSize, nums, numsSize, n, k, 1);
    
    /* free the memory */
    free(ansSize);
    free(nums);
    free(numsSize);
    
    for(int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = k;
    }
    
    return ans;
}

int main(int argc, char **argv) {
    int n = 4;
    int k = 2;
    int *returnSize = (int *)calloc(1, sizeof(int));
    int *returnColumnSizes = NULL;
    
    int **ans = combine(n, k, returnSize, &returnColumnSizes);
    for(int i = 0; i < *returnSize; ++i) {
        for(int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    
    /* free the memory */
    for(int i = 0; i < *returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
    free(returnSize);
    return 0;
}
