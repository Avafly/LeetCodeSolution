#include <stdio.h>
#include <stdlib.h>

#define SIZE 20000

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int **ans = (int **)malloc(SIZE * sizeof(int *));
    int count = 0;

    for(int i = 0; i < numsSize - 2; ++i) {
        while(i > 0 && i < numsSize && nums[i] == nums[i - 1]) {
            ++i;
        }
        int j = i + 1;
        int k = numsSize - 1;
        while(j < k) {
            int target = -nums[i];
            int sum = nums[j] + nums[k];
            if(sum == target) {
                ans[count] = (int *)malloc(3 * sizeof(int));
                ans[count][0] = nums[i];
                ans[count][1] = nums[j];
                ans[count][2] = nums[k];
                ++count;
                ++j;
                --k;

                while(j - 1 != i && j < k && nums[j] == nums[j - 1]) {
                    ++j;
                }
                while(k < numsSize - 1 && j < k && nums[k] == nums[k + 1]) {
                    --k;
                }
            }
            if(sum < target) {
                ++j;
            }
            if(sum > target) {
                --k;
            }
        }
    }
    
    *returnColumnSizes = (int *)malloc(count * sizeof(int));
    for(int i = 0; i < count; ++i) {
        (*returnColumnSizes)[i] = 3;
    }
    *returnSize = count;

    return ans;
}

int main(int argc, char **argv) {
    int nums[] = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    int returnSize;
    int *returnColumnSizes;

    int **ans = threeSum(nums, sizeof(nums) / sizeof(int), &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; ++i) {
        printf("%d\t%d\t%d\n", ans[i][0], ans[i][1], ans[i][2]);
    }

    // free the memory
    for(int i = 0; i < returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);

    return 0;
}
