#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int numsSize = nums.size();
        int closest = nums[0]+nums[1]+nums[2];

        sort(nums.begin(), nums.end());

        for(int i=0; i<numsSize-2; ++i) {
            while(i>0 && i<numsSize && nums[i]==nums[i-1])
                ++i;
            int j = i + 1;
            int l = numsSize - 1;

            closest = abs(target-closest)<abs(target-(nums[0]+nums[1]+nums[2])) ? closest : nums[0]+nums[1]+nums[2];

            while (j < l) {
                int sum = nums[i] + nums[j] + nums[l];

                if(sum < target) {
                    ++j;
                    closest = abs(target-closest)<abs(target-sum) ? closest : sum;
                }
                else if(sum > target) {
                    --l;
                    closest = abs(target-closest)<abs(target-sum) ? closest : sum;
                }
                else {
                    return target;
                }

                while(j-1!=i && j<l && nums[j]==nums[j-1])
                    ++j;
                while(l<numsSize-1 && j<l && nums[l]==nums[l+1])
                    --l;
            }
        }

        return closest;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    //vector<int> nums = {0, 0, 0};
    vector<int> nums = {4,0,5,-5,3,3,0,-4,-5};
    int target = -2;

    cout << sol.threeSumClosest(nums, target) << endl;

    return 0;
}