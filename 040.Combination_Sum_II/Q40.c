
// LeetCode Problem:
// Title: Combination Sum II
// URL: https://leetcode.com/problems/combination-sum-ii/

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 200

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void findComb(int *candidates, int candidatesSize, int target, int start, int *comb, int *combLen, int **ans, int *count, int *returnColumnSizes) {
    if(target == 0) {
        // append comb to answer
        ans[*count] = (int *)malloc(sizeof(int) * (*combLen));
        for(int i = 0; i < *combLen; ++i) {
            ans[*count][i] = comb[i];
        }
        returnColumnSizes[*count] = *combLen;
        ++(*count);
        return;
    }

    for(int i = start; i < candidatesSize;) {
        int jump = 1;
        if(candidates[i] <= target) {
            comb[*combLen] = candidates[i];
            ++(*combLen);
            findComb(candidates, candidatesSize, target - candidates[i], i + 1, comb, combLen, ans, count, returnColumnSizes);
            --(*combLen);

            // jump to the index with different element
            while(i + jump < candidatesSize) {
                if(candidates[i + jump] == candidates[i]) {
                    ++jump;
                }
                else {
                    break;
                }
            }
        }
        i += jump;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), compare);

    // setup of return parameters
    int **ans = (int **)malloc(sizeof(int *) * CAPACITY);
    *returnSize = CAPACITY;
    *returnColumnSizes = (int *)malloc(sizeof(int) * CAPACITY);

    int *count = (int *)calloc(1, sizeof(int));
    int *comb = (int *)malloc(sizeof(int) * CAPACITY);
    int *combLen = (int *)calloc(1, sizeof(int));

    findComb(candidates, candidatesSize, target, 0, comb, combLen, ans, count, *returnColumnSizes);

    *returnSize = *count;

    free(combLen);
    free(count);
    free(comb);
    return ans;
}

int main(int argc, char **argv) {

    int nums[] = {10,1,2,7,6,1,5};
    int target = 8;
    int numsSize = sizeof(nums) / sizeof(int);

    // create candidates
    int *candidates = (int *)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; ++i) {
        candidates[i] = nums[i];
    }

    int *returnSize = (int *)malloc(sizeof(int));
    int *returnColumnSizes = NULL;

    int **ans = combinationSum2(candidates, numsSize, target, returnSize, &returnColumnSizes);

    for(int i = 0; i < *returnSize; ++i) {
        for(int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    // deallocate the memory
    for(int i = 0; i < *returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(candidates);
    free(returnColumnSizes);
    free(returnSize);
    return 0;
}