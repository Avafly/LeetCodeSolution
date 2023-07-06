#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;

        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] != val) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    for(int i=0; i<nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution sol = Solution();

    int val = 2;
    int len = sol.removeElement(nums, val);

    for(int i=0; i<len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}