#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);

        while(left <= right) {
            int mid = left + (right - left) / 2;
            // target is found
            if(nums[mid] == target) {
                return true;
            }
            // if the left side is sorted
            if(nums[left] < nums[mid]) {
                // if the target is in left side
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                // otherwise, search in right side
                else {
                    left = mid + 1;
                }
            }
            // if the right side is sorted
            else if(nums[left] > nums[mid]) {
                // if the target is in left side
                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                // otherwise, search in left side
                else {
                    right = mid - 1;
                }
            }
            else {
                ++left;
            }
        }

        return false;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1,0,1,1,1};
    int target = 0;

    Solution sol;
    cout << (sol.search(nums, target) ? "True" : "False") << endl;

    return 0;
}