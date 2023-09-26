
// LeetCode Problem:
// Title: Combination Sum
// URL: https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        findComb(candidates, target, 0, comb, ans);
        return ans;
    }

private:
    void findComb(vector<int> &candidates, int target, int start, vector<int> &comb, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(comb);
            return;
        }

        for(int i = start; i < candidates.size(); ++i) {
            if(candidates[i] <= target) {
                comb.push_back(candidates[i]);
                findComb(candidates, target - candidates[i], i, comb, ans);
                comb.pop_back();
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = sol.combinationSum(candidates, target);

    // print answer
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}