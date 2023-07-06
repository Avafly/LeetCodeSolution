#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ans = (int *)calloc(2, sizeof(int));
    ans[0] = -1;
    ans[1] = -1;
    *returnSize = 2;

    for(int i = 0; i < numsSize; ++i) {
        if(nums[i] == target) {
            if(ans[0] == -1) {
                ans[0] = i;
            }
            ans[1] = i;
        }
    }

    return ans;
}

int main(int argc, char **argv) {
    int nums[] = {5,7,7,8,8,10};
    int target = 6;
    int *returnSize = (int *)malloc(sizeof(int));

    int *ans = searchRange(nums, sizeof(nums) / sizeof(int), target, returnSize);

    printf("[%d, %d]\n", ans[0], ans[1]);

    /* free the memory */
    free(ans);
    free(returnSize);
    return 0;
}