
// LeetCode Problem:
// Title: 3Sum
// URL: https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int numsSize = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < numsSize - 2; ++i) {
            while(i > 0 && i < numsSize && nums[i] == nums[i - 1]) {
                ++i;
            }
            int j = i + 1;
            int k = numsSize - 1;
            while(j < k) {
                int target = -nums[i];
                int sum = nums[j] + nums[k];
                if(target == sum) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while(j - 1 != i && j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while(k < numsSize - 1 && j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
                if(target > sum) {
                    ++j;
                }
                if(target < sum) {
                    --k;
                }
            }
        }
        
        return ans;
    }
};

int main(int argc, char **argv) {
   vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    //vector<int> nums = {0,1,1};
    //vector<int> nums = {0,0,0,0};
    //vector<int> nums = {-1,0,1,2,-1,-4};
    
    Solution sol = Solution();
    vector<vector<int>> ans = sol.threeSum(nums);

    cout << ans.size() << endl;

    return 0;
}
