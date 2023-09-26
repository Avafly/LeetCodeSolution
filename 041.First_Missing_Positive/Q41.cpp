
// LeetCode Problem:
// Title: First Missing Positive
// URL: https://leetcode.com/problems/first-missing-positive/

#include <iostream>
#include <vector>
using namespace std;

/*

    1. Iterate through the array, checking each number at position i, nums[i].
    2. If nums[i] is a positive integer greater than 0 and less than or equal to n
       (where n is the length of the array), and nums[i] is not equal to the number
       that should be at its position (i.e., nums[nums[i] - 1] != nums[i]), then
       swap the values of nums[i] and nums[nums[i] - 1]. This operation puts nums[i]
       in the correct position.
    3. Continue checking the swapped nums[i] until nums[i] no longer satisfies the
       above condition. Then proceed to the next element.
    4. After completing the first pass through the array, iterate through the array
       again, finding the first position i where nums[i] is not equal to i + 1. The
       missing smallest positive integer is i + 1.
    5. If no such position is found during the second pass, it means the array
       contains all integers from 1 to n. In this case, the missing smallest positive
       integer is n + 1.

*/

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};


int main(int argc, char **argv) {

    Solution sol = Solution();

    vector<int> nums = {1, 1};
    cout << sol.firstMissingPositive(nums) << endl;

    return 0;
}