
// LeetCode Problem:
// Title: Trapping Rain Water
// URL: https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
using namespace std;

/*

  Initialize two pointers, left and right, at the beginning and end of the height
array. Also, initialize left_max and right_max to store the maximum height on
the left and right of the pointers.
  While the left pointer is less than the right pointer, compare the heights at the
left and right pointers. If the height at the left pointer is smaller, this means
that the amount of trapped water depends on the left_max. Update left_max and
calculate the trapped water at the left pointer. Then, increment the left pointer.
Similarly, if the height at the right pointer is smaller, update right_max and
calculate the trapped water at the right pointer, then decrement the right pointer.

*/

class Solution {
public:
    int trap(vector<int> &height) {
        int trapped_water = 0;
        int left = 0;
        int right = height.size() - 1;
        int max_left = height[left];
        int max_right = height[right];

        while(left < right) {
            if(height[left] < height[right]) {
                ++left;
                if(max_left <= height[left]) {
                    max_left = height[left];
                }
                else {
                    trapped_water += max_left - height[left];
                }
            }
            else {
                --right;
                if(max_right <= height[right]) {
                    max_right = height[right];
                }
                else {
                    trapped_water += max_right - height[right];
                }
            }
        }

        return trapped_water;
    }
};

int main(int argc, char **argv) {

    Solution sol = Solution();
    //vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {4,2,0,3,2,5};
    cout << sol.trap(height) << endl;

    return 0;
}