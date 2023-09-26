
// LeetCode Problem:
// Title: Search in Rotated Sorted Array II
// URL: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(int *nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        // target is found
        if(nums[mid] == target) {
            return true;
        }
        // if the left side is sorted
        if(nums[left] < nums[mid]) {
            // if the target is in left side
            if(nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            }
            // otherwise, search in right side
            else {
                left = mid + 1;
            }
        }
        // if the right side is sorted
        else if(nums[left] > nums[mid]) {
            // if the target is in left side
            if(nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            }
            // otherwise, search in left side
            else {
                right = mid - 1;
            }
        }
        else {
            ++left;
        }
    }

    return false;
}

int main(int argc, char **argv) {
    int nums[] = {4, 5, 6, 9, 0, 1, 2, 3};
    int target = 0;

    printf("%d\n", search(nums, sizeof(nums)/sizeof(int), target));

    return 0;
}