#include <stdio.h>

void sortColors(int* nums, int numsSize){
    int counts[3] = {0};
    for(int i = 0; i < numsSize; ++i) {
        ++counts[nums[i]];
    }
    for(int i = 0; i < numsSize; ++i) {
        if(counts[0] != 0) {
            nums[i] = 0;
            --counts[0];
        }
        else if(counts[1] != 0) {
            nums[i] = 1;
            --counts[1];
        }
        else {
            nums[i] = 2;
        }
    }
}

int main(int argc, char **argv) {
    int nums[] = {2,0,2,1,1,0};
    int numsSize = sizeof(nums) / sizeof(int);
    sortColors(nums, numsSize);

    for(int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}