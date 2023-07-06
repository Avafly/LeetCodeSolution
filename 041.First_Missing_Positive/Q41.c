#include <stdio.h>

/*

    1. Iterate through the array, checking each number at position i, nums[i].
    2. If nums[i] is a positive integer greater than 0 and less than or equal to n
       (where n is the length of the array), and nums[i] is not equal to the number
       that should be at its position (i.e., nums[nums[i] - 1] != nums[i]), then
       swap the values of nums[i] and nums[nums[i] - 1]. This operation puts nums[i]
       in the correct position.
    3. Continue checking the swapped nums[i] until nums[i] no longer satisfies the
       above condition. Then proceed to the next element.
    4. After completing the first pass through the array, iterate through the array
       again, finding the first position i where nums[i] is not equal to i + 1. The
       missing smallest positive integer is i + 1.
    5. If no such position is found during the second pass, it means the array
       contains all integers from 1 to n. In this case, the missing smallest positive
       integer is n + 1.

*/

void swap(int *l, int *r){
    // if l == r, the XOR-based swap will set the value to zero
    if(*l != *r) {
        *l = *l ^ *r;
        *r = *r ^ *l;
        *l = *l ^ *r;
    }
}

int firstMissingPositive(int* nums, int numsSize){

    for(int i = 0; i < numsSize; ++i) {
        while(nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            // swap
            swap(&nums[nums[i] - 1], &nums[i]);
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
