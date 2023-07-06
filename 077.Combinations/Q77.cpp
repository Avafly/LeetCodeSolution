#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        
        rec(ans, nums, n, k, 1);

        return ans;
    }
private:
    void rec(vector<vector<int>> &ans, vector<int> &nums, int n, int k, int start) {
        if(nums.size() == k) {
            ans.push_back(nums);
            return;
        }
        for(int i = start; i <= n; ++i) {
            nums.push_back(i);
            rec(ans, nums, n, k, i + 1);
            nums.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    int n = 4;
    int k = 2;
    
    Solution sol;
    vector<vector<int>> ans = sol.combine(n, k);
    for(auto &entry : ans) {
        for(auto &n : entry) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
