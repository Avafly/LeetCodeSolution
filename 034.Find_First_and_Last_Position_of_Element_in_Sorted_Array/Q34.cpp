#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};

        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] == target) {
                if(ans[0] == -1) {
                    ans[0] = i;
                }
                ans[1] = i;
            }
        }


        return ans;
    }
};

int main(int argc, char **argv) {

    vector<int> nums = {5, 6, 7, 7, 8, 8, 10};
    int target = 7;

    Solution sol = Solution();
    vector<int> ans = sol.searchRange(nums, target);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}