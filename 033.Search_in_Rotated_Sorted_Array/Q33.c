#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){

    int left = 0;
    int right = numsSize - 1;

    if(nums[numsSize-1] >= target) {
        while(left <= right) {
            int midI = (left+right) / 2;
            if(nums[midI] == target) {
                return midI;
            }
            else if(nums[midI]>nums[numsSize-1] || nums[midI]<target) {
                left = midI + 1;
            }
            else {
                right = midI - 1;
            }
        }
    }
    else {
        while(left <= right) {
            int midI = (left+right) / 2;
            if(nums[midI] == target) {
                return midI;
            }
            else if(nums[midI]<nums[0] || nums[midI]>target) {
                right = midI - 1;
            }
            else {
                left = midI + 1;
            }
        }
    }

    return -1;
}

int main(int argc, char **argv) {
    int nums[] = {4, 5, 6, 9, 0, 1, 2, 3};
    int target = 0;

    printf("%d\n", search(nums, sizeof(nums)/sizeof(int), target));

    return 0;
}