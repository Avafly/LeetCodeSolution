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

    vector<int> nums = {2,3,0,1,4};
    cout << sol.jump(nums) << endl;

    return 0;
}