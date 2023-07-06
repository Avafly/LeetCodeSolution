#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void rec(int **ans, int *ansSize, int *nums, int numsSize, int *subset, int *subsetSize, int *returnColumnSizes, int start) {
    returnColumnSizes[*ansSize] = *subsetSize;
    ans[*ansSize] = (int *)malloc(sizeof(int) * (*subsetSize));
    memcpy(ans[(*ansSize)++], subset, sizeof(int) * (*subsetSize));
    for(int i = start; i < numsSize; ++i) {
        subset[(*subsetSize)++] = nums[i];
        rec(ans, ansSize, nums, numsSize, subset, subsetSize, returnColumnSizes, i + 1);
        --(*subsetSize);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = pow(2, numsSize);
    *returnColumnSizes = (int *)calloc(*returnSize, sizeof(int));
    int **ans = (int **)calloc(*returnSize, sizeof(int *));
    int *ansSize = (int *)calloc(1, sizeof(int));
    int *subset = (int *)calloc(numsSize, sizeof(int));
    int *subsetSize = (int *)calloc(1, sizeof(int));
    
    rec(ans, ansSize, nums, numsSize, subset, subsetSize, *returnColumnSizes, 0);
    
    /* free the memory */
    free(ansSize);
    free(subset);
    free(subsetSize);
    
    return ans;
}

int main(int argc, char **argv) {
    int nums[] = {1, 2, 3};
    int *returnSize = (int *)calloc(1, sizeof(int));
    int *returnColumnSizes = NULL;
    
    int **ans = subsets(nums, sizeof(nums) / sizeof(int), returnSize, &returnColumnSizes);
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