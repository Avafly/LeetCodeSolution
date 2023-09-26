
// LeetCode Problem:
// Title: Permutations
// URL: https://leetcode.com/problems/permutations/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        rec(ans, nums, arr, nums.size());

        return ans;
    }

private:
    void rec(vector<vector<int>> &ans, vector<int> num, vector<int> arr, int n) {
        if(arr.size() == n) {
            ans.push_back(arr);
            return;
        }
        for(int i = 0; i < num.size(); ++i) {
            arr.push_back(num[i]);
            num.erase(num.begin() + i);
            rec(ans, num, arr, n);

            // undo previous change
            num.insert(num.begin() + i, arr.back());
            arr.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();
    vector<int> nums = {0, 1, 2};

    vector<vector<int>> ans = sol.permute(nums);

    for(auto row : ans) {
        for(auto item : row) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}