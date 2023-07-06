#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int count = 1;
    int ansSize = 1;
    
    for(int i = 1; i < numsSize; ++i) {
        if(nums[i] == nums[ansSize - 1]) {
            if(count >= 2) {
                continue;
            }
            else {
                nums[ansSize++] = nums[i];
                ++count;
            }
        }
        else {
            count = 1;
            nums[ansSize++] = nums[i];
        }
    }

    return ansSize;
}

int main(int argc, char **argv) {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(int);

    numsSize = removeDuplicates(nums, numsSize);

    for(int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}