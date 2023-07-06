#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int  numsSize = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());

        for(int i = 0; i < numsSize - 3; ++i) {
            while(i > 0 && i < numsSize && nums[i] == nums[i - 1]) {
                ++i;
            }
            for(int j = i + 1; j < numsSize - 2; ++j) {
                while(j - 1 > i && j < numsSize && nums[j] == nums[j - 1]) {
                    ++j;
                }
                int start = j + 1;
                int end = numsSize - 1;
                while(start < end) {
                    long tar = (long)target-(long)(nums[i] + nums[j]);
                    long sum = (long)nums[start] + (long)nums[end];
                    if(sum < tar) {
                        ++start;
                    }
                    else if(sum > tar) {
                        --end;
                    }
                    else {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        ++start;
                        --end;
                        while(start-1>j && start<end && nums[start]==nums[start-1]) {
                            ++start;
                        }
                        while(end<numsSize-1 && start<end && nums[end]==nums[end+1]) {
                            --end;
                        }
                    }
                    
                }
            }
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = 0;

    vector<vector<int>> ans = sol.fourSum(nums, target);

    int len = static_cast<int>(ans.size());
    for(int i = 0; i < len; ++i) {
        cout << ans[i][0] << " " << ans[i][1] << " ";
        cout << ans[i][2] << " " << ans[i][3] << endl;
    }
    cout << len << endl;

    return 0;
}
