
// LeetCode Problem:
// Title: Jump Game
// URL: https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int next_max_pos = 0;
        int current_max_pos = 0;
        int numsSize = nums.size();

        for(int i = 0; i < numsSize - 1; ++i) {
            next_max_pos = max(next_max_pos, i + nums[i]);
            // the farthest position
            if(current_max_pos == i) {
                current_max_pos = next_max_pos;
            }
            if(current_max_pos >= numsSize - 1) {
                break;
            }
            // if the farthest position's value == 0, return false
            if(nums[i] == 0 && current_max_pos == i) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {

    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    cout << (sol.canJump(nums) ? "True" : "False") << endl;
    return 0;
}