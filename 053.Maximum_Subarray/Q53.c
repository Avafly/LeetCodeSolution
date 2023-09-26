
// LeetCode Problem:
// Title: Maximum Subarray
// URL: https://leetcode.com/problems/maximum-subarray/

#include <stdio.h>
#include <limits.h>

#define MAX(a, b)   ((a) > (b) ? (a) : (b))

int maxSubArray(int *nums, int numsSize){

    int ans = INT_MIN;
    int sum = 0;

    for(int i = 0; i < numsSize; ++i) {
        sum += nums[i];
        ans = MAX(ans, sum);
        if(sum < 0) { sum = 0; }
    }

    return ans;
}

int main(int argc, char **argv) {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};

    printf("%d\n", maxSubArray(nums, sizeof(nums) / sizeof(int)));

    return 0;
}