
// LeetCode Problem:
// Title: Merge Sorted Array
// URL: https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

/*
 Time complexity: O(m + n)
 */

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> nums(m + n, 0);
        int i1 = 0, i2 = 0;
        
        while(i1 + i2 < m + n) {
            if(i1 < m && (i2 >= n || nums1[i1] < nums2[i2])) {
                nums[i1 + i2] = nums1[i1];
                ++i1;
            }
            else if(i2 < n) {
                nums[i1 + i2] = nums2[i2];
                ++i2;
            }
        }
        nums1 = nums;
    }
};

int main(int argc, char **argv) {
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    int m = 1;
    int n = 1;
    
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    
    for(auto &n : nums1) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}
