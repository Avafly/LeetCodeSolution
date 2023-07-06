#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
   return (*(int*)a - *(int*)b);
}

void nextPermutation(int* nums, int numsSize) {
    int k, l = numsSize;

    // retrieve the element smaller than the right-hand elements
    for(k=numsSize-2; k>-1; k--){
        if(nums[k] < nums[k+1])
            break;
    }

    if(k < 0) 
        qsort(nums, numsSize, sizeof(int), compare);

    else{
        // retrieve the element that only bigger than nums[k]
        for(l=numsSize-1; l>k; l--){
            if(nums[k] < nums[l])
                break;
        }
        // swap each other
        int tmp = nums[k];
        nums[k] = nums[l];
        nums[l] = tmp;

        qsort(nums+k+1, numsSize-k-1, sizeof(int), compare);
    }
}

int main(int argc, char **argv) {
    int nums[] = {5,3,4,2,1};
    int numsSize = sizeof(nums) / sizeof(int);

    for(int i=0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n- - - - - - - - -\n");

    nextPermutation(nums, numsSize);

    for(int i=0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}