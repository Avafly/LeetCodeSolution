#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int midI;

        while(left <= right) {
            midI = (left+right) / 2;
            if(nums[midI] == target) {
                return midI;
            }
            else if(nums[midI] < target) {
                left = midI + 1;
            }
            else {
                right = midI - 1;
            }
        }

        return max(left, right);
    }
};

int main(int argc, char **argv) {

    vector<int> nums = {1, 3};
    int target = 0;

    Solution sol = Solution();
    cout << sol.searchInsert(nums, target) << endl;

    return 0;
}