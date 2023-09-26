// LeetCode Problem:
// Title: Two Sum
// URL: https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> idx_map;

        for(size_t i = 0; i < nums.size(); ++i) {
            int num2 = target - nums[i];
            if(idx_map.count(num2)) {
                return {idx_map[num2], static_cast<int>(i)};
            }
            else {
                idx_map[nums[i]] = static_cast<int>(i);
            }
        }
        return {-1, -1};
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1,3,4,2};
    int target = 6;
    
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    
    for(auto &n : ans) cout << n << " ";
    cout << endl;
    
    return 0;
}
