#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0};
        for(int i = 0; i < nums.size(); ++i) {
            ++counts[nums[i]];
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(counts[0] != 0) {
                nums[i] = 0;
                --counts[0];
            }
            else if(counts[1] != 0) {
                nums[i] = 1;
                --counts[1];
            }
            else {
                nums[i] = 2;
            }
        }
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {2, 0, 1};
    Solution sol;
    sol.sortColors(nums);

    for(int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}