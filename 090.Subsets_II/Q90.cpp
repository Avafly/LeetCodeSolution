
// LeetCode Problem:
// Title: Subsets II
// URL: https://leetcode.com/problems/subsets-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        rec(ans, nums, subset, 0);
        return ans;
    }
private:
    void rec(vector<vector<int>> &ans, vector<int> &nums, vector<int> &subset, int start) {
        ans.push_back(subset);
        for(int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            rec(ans, nums, subset, i + 1);
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                ++i;
            }
            subset.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 2, 2, 3, 2};
    
    Solution sol;
    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    
    for(auto &subset : ans) {
        for(auto &n : subset) {
            cout << n << " ";
        }
        cout << endl;
    }
    
    return 0;
}
