#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
    int count = 0;

    for(int i=1; i<numsSize; ++i) {
        if(nums[i] != nums[count]) {
            nums[++count] = nums[i];
        }
    }
    return count + 1;
}

int main(int argc, char **argv) {

    int nums[] = {1, 1, 2};
    int len = sizeof(nums) / sizeof(int);

    for(int i=0; i<len; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("%d\n", removeDuplicates(nums, len));

    for(int i=0; i<len; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}