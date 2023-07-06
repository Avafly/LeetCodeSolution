#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;

        for(int i=1; i<nums.size(); ++i) {
            if(nums[i] != nums[count]) {
                nums[++count] = nums[i];
            }
        }
        return count + 1;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    for(int i=0; i<nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution sol = Solution();

    int len = sol.removeDuplicates(nums);

    for(int i=0; i<len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}