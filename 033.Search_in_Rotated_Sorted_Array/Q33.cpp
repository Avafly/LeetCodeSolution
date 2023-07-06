#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        int left = 0;
        int right = len-1;

        if(nums[len-1] >= target) {
            while(left <= right) {
                int midI = (left+right) / 2;
                if(nums[midI] == target) {
                    return midI;
                }
                else if(nums[midI]>nums[len-1] || nums[midI]<target) {
                    left = midI + 1;
                }
                else {
                    right = midI - 1;
                }
            }
        }
        else {
            while(left <= right) {
                int midI = (left+right) / 2;
                if(nums[midI] == target) {
                    return midI;
                }
                else if(nums[midI]<nums[0] || nums[midI]>target) {
                    right = midI - 1;
                }
                else {
                    left = midI + 1;
                }
            }
        }
        
        return -1;
    }
};


int main(int argc, char **argv) {

    vector<int> nums = {4, 5, 6, 9, 0, 1, 2, 3};
    int target = 4;

    Solution sol = Solution();
    cout << sol.search(nums, target) << endl;

    return 0;
}