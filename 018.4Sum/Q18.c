
// LeetCode Problem:
// Title: 4Sum
// URL: https://leetcode.com/problems/4sum/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 30000

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), compare);
    int **ans = (int **)malloc(sizeof(int *) * SIZE);
    int count = 0;

    for(int i = 0; i < numsSize - 3; ++i) {
        while(i > 0 && i < numsSize && nums[i] == nums[i - 1]) {
            ++i;
        }
        for(int j = i + 1; j < numsSize - 2; ++j) {
            while(j - 1 > i && j < numsSize && nums[j] == nums[j - 1]) {
                ++j;
            }
            int start = j + 1;
            int end = numsSize - 1;
            while(start < end) {
                long tar = (long)target - (long)(nums[i] + nums[j]);
                long sum = (long)nums[start] + (long)nums[end];
                if(sum < tar) {
                    ++start;
                }
                else if(sum > tar) {
                    --end;
                }
                else {
                    ans[count] = (int *)malloc(sizeof(int) * 4);
                    ans[count][0] = nums[i];
                    ans[count][1] = nums[j];
                    ans[count][2] = nums[start];
                    ans[count++][3] = nums[end];
                    ++start;
                    --end;
                    while(start - 1 > j && start < end && nums[start] == nums[start - 1]) {
                        ++start;
                    }
                    while(end < numsSize - 1 && start < end && nums[end] == nums[end + 1]) {
                        --end;
                    }
                }
            }
        }
    }

    // create return parameters
    *returnSize = count;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = 4;
    }

    return ans;
}

int main(int argc, char **argv) {
    int nums[] = {1,0,-1,0,-2,2};
    int target = 0;

    int returnSize = 0;
    int *returnColumnSizes = NULL;

    int **ans = fourSum(nums, sizeof(nums) / sizeof(int), target, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; ++i) {
        printf("{%d %d %d %d}\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    }

    // free the memory
    for(int i = 0; i < returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
    return 0;
}
