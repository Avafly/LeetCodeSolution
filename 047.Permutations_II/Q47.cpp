#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Key idea:
After sorting, if num[i] == num[i - 1], a duplicate permutation occurs;
thus just skip this calculation.

*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
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
            if(i > 0 && num[i] == num[i - 1]) {
                continue;
            }

            arr.push_back(num[i]);
            num.erase(num.begin() + i);
            rec(ans, num, arr, n);

            num.insert(num.begin() + i, arr.back());
            arr.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    vector<int> nums = {2, 1, 3};
    vector<vector<int>> ans = sol.permuteUnique(nums);
    
    for(auto row : ans) {
        for(auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }


    return 0;
}