#include <stdio.h>

/*
    nums[nums[i] - 1] != nums[i]:
    The value of current element is nums[i], but the value of the place that should
    record this value is not nums[i].

    nums[i] - 1 != i:
    This element should be placed at 0, but the index of this element is not 0.
*/

int firstMissingPositive(int* nums, int numsSize){

    for(int i = 0; i < numsSize; ++i) {
        while(nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            // swap
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }

    for(int i = 0; i < numsSize; ++i) {
        if(nums[i] != i + 1) {
            return i + 1;
        }
    }

    return numsSize + 1;
}

int main(int argc, char **argv) {

    int nums[] = {1,1};
    printf("%d\n", firstMissingPositive(nums, sizeof(nums) / sizeof(int)));

    return 0;
}