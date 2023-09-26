
// LeetCode Problem:
// Title: Jump Game
// URL: https://leetcode.com/problems/jump-game/

#include <stdio.h>
#include <stdbool.h>

#define Max(a, b) ((a) > (b) ? (a) : (b))

bool canJump(int *nums, int numsSize){
    int next_max_pos = 0;
    int current_max_pos = 0;

    for(int i = 0; i < numsSize - 1; ++i) {
        next_max_pos = Max(next_max_pos, i + nums[i]);
        // the farthest position
        if(current_max_pos == i) {
            current_max_pos = next_max_pos;
        }
        if(current_max_pos >= numsSize - 1) {
            break;
        }
        if(nums[i] == 0 && current_max_pos == i) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char *argv[]) {
    int nums[] = {2,3,1,1,4};

    printf("%s\n", canJump(nums, sizeof(nums) / sizeof(int)) ? "True" : "False");

    return 0;
}
