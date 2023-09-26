
// LeetCode Problem:
// Title: Jump Game II
// URL: https://leetcode.com/problems/jump-game-ii/

#include <stdio.h>

/*
The key idea of this solution is that we looking for the farthest position
that can be reached at every step, to reduce the jump time as possible,
i.e., greedy.
*/

#define Max(a, b) ((a) > (b) ? (a) : (b))

int jump(int* nums, int numsSize){
    int next_max_pos = 0;
    int current_max_pos = 0;
    int count = 0;

    for(int i = 0; i < numsSize - 1; ++i) {
        next_max_pos = Max(next_max_pos, i + nums[i]);
        if(current_max_pos == i) {
            ++count;
            current_max_pos = next_max_pos;
        }
        if(current_max_pos >= numsSize) {
            break;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    int nums[] = {1, 6, 1, 1, 8, 2, 1, 1, 2, 3, 1, 1, 1, 5};
    printf("%d\n", jump(nums, sizeof(nums) / sizeof(int)));
    return 0;
}