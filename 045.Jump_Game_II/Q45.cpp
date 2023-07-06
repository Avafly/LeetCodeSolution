#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
The key idea of this solution is that we looking for the farthest position
that can be reached at every step, to reduce the jump time as possible,
i.e., greedy.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) {
            return 0;
        }

        int count = 0;
        int current_max_pos = 0;
        int next_max_pos = 0;

        for(int i = 0; i < n - 1; ++i) {
            next_max_pos = max(next_max_pos, i + nums[i]);
            if(i == current_max_pos) {
                count++;
                current_max_pos = next_max_pos;
            }
            if(current_max_pos >= n - 1) {
                break;
            }
        }

        return count;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    vector<int> nums = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    //vector<int> nums = {2,3,0,1,4};
    cout << sol.jump(nums) << endl;

    return 0;
}