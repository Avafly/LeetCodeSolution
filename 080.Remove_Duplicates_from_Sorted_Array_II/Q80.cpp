#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int ansSize = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[ansSize - 1]) {
                if(count >= 2) {
                    continue;
                }
                else {
                    nums[ansSize++] = nums[i];
                    ++count;
                }
            }
            else {
                count = 1;
                nums[ansSize++] = nums[i];
            }
        }

        return ansSize;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    Solution sol;

    int numsSize = sol.removeDuplicates(nums);
    for(int i = 0; i < numsSize; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}