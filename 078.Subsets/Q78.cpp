#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
            subset.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 2, 3};
    
    Solution sol;
    vector<vector<int>> ans = sol.subsets(nums);
    
    for(auto &subset : ans) {
        for(auto &n : subset) {
            cout << n << " ";
        }
        cout << endl;
    }
    
    return 0;
}