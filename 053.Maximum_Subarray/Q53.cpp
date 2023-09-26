
// LeetCode Problem:
// Title: Maximum Subarray
// URL: https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = INT_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0) { sum = 0; }
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    vector<int> nums = {1, 2, 3, 4 ,5};
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}