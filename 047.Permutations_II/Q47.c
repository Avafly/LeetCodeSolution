#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 720

void swap(int *l, int *r){
    // if l == r, the XOR-based swap will set the value to zero
    if(*l != *r) {
        *l = *l ^ *r;
        *r = *r ^ *l;
        *l = *l ^ *r;
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void rec(int **ans, int *nums, int start, int *count, int n) {
    if(start == n) {
        // append the array to answer
        ans[*count] = (int *)malloc(sizeof(int) * n);
        memcpy(ans[(*count)++], nums, sizeof(int) * n);
        return;
    }
    bool mark[21] = {0};
    for(int i = start; i < n; ++i) {
        if(mark[nums[i] + 10]) {
            continue;
        }
        mark[nums[i] + 10] = true;
        swap(&nums[start], &nums[i]);
        rec(ans, nums, start + 1, count, n);
        swap(&nums[start], &nums[i]);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int **ans = (int **)malloc(sizeof(int *) * SIZE);
    int *count = (int *)calloc(1, sizeof(int));
    
    qsort(nums, numsSize, sizeof(int), compare);
    rec(ans, nums, 0, count, numsSize);
    
    *returnSize = *count;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < (*returnSize); ++i) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    free(count);
    return ans;
}

int main(int argc, char **argv) {
    int nums[] = {3, 2, 1};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize;
    int *returnColumnSizes = NULL;

    int **ans = permuteUnique(nums, numsSize, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; ++i) {
        for(int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    /* free the memory */
    for(int i = 0; i < returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);

    return 0;
}
