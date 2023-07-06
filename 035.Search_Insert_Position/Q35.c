#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int midI;

    while(left <= right) {
        midI = (left+right) / 2;
        if(nums[midI] == target) {
            return midI;
        }
        else if(nums[midI] < target) {
            left = midI + 1;
        }
        else {
            right = midI - 1;
        }
    }

    return left>right ? left : right;
}

int main(int argc, char **argv) {
    int nums[] = {1, 3, 5, 7, 9};
    int target = 6;

    printf("%d\n", searchInsert(nums, sizeof(nums)/sizeof(int), target));

    return 0;
}