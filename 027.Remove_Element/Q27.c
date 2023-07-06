#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val){
    int count = 0;

    for(int i=0; i<numsSize; ++i) {
        if(nums[i] != val) {
            nums[count++] = nums[i];
        }
    }
    return count;
}

int main(int argc, char **argv) {

    int nums[] = {3, 2, 2, 3};
    int len = sizeof(nums) / sizeof(int);

    for(int i=0; i<len; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int val = 4;
    printf("%d\n", removeElement(nums, len, val));

    for(int i=0; i<len; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}