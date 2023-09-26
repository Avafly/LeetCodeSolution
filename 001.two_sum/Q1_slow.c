// LeetCode Problem:
// Title: Two Sum
// URL: https://leetcode.com/problems/two-sum/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ans = (int *)calloc(2, 2 * sizeof(int)); // allocate the memory space for array
    for(int i = 0; i < numsSize; ++i){
        for (int j = i + 1; j < numsSize; ++j){
            if ((nums[i] + nums[j]) == target) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}

int main(int argc, char **argv) {
    int nums[] = {1,3,4,2};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 6;
    int returnSize;
    
    int *ans = twoSum(nums, numsSize, target, &returnSize);
    printf("%d %d\n", ans[0], ans[1]);
    
    free(ans);
    
    return 0;
}
