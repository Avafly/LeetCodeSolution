#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        findComb(candidates, target, 0, comb, ans);
        return ans;
    }

private:
    void findComb(vector<int>& candidates, int target, int start, vector<int> &comb, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(comb);
            return;
        }

        for(int i = start; i < candidates.size();) {
            int jump = 1;
            if(candidates[i] <= target) {
                comb.push_back(candidates[i]);
                findComb(candidates, target - candidates[i], i + 1, comb, ans);
                comb.pop_back();

                // jump to the index with different element
                while(i + jump < candidates.size()) {
                    if(candidates[i + jump] == candidates[i])
                        ++jump;
                    else
                        break;
                }
            }
            i += jump;
        }
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    vector<int> candidates = {2,5,2,1,2};
    int target = 5;

    vector<vector<int>> ans = sol.combinationSum2(candidates, target);

    // print answer
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}