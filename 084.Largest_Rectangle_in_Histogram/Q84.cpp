
// LeetCode Problem:
// Title: Largest Rectangle in Histogram
// URL: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 Idea: monotonic stack
 The non-decreasing monotonic stack records the index of heights. The previous
 index of the i-th index (i.e., index_{i}), index_{i-1}, represents the index
 where the height is smaller than height[index_{i}]. Therefore, the lowest
 height between index_{i-1} + 1 and index_{i} is height[index_{i}]. Then, the
 width can be computed by index_{i} - index_{i-1} - 1, and the area can be
 calculated by width * height.
 */

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = static_cast<int>(heights.size());
        stack<int> monoStack;
        int ans = 0;

        // iterate through the heights vector
        for(int i = 0; i < n; ++i) {
            // ensure the stack is non-decreasing
            while(!monoStack.empty() && heights[i] <= heights[monoStack.top()]) {
                int topIndex = monoStack.top();
                monoStack.pop();
                int width = monoStack.empty() ? i : i - monoStack.top() - 1;
                ans = max(ans, heights[topIndex] * width);
            }
            monoStack.push(i);
        }

        // process the remaining elements in the stack
        while(!monoStack.empty()) {
            int topIndex = monoStack.top();
            monoStack.pop();
            int width = monoStack.empty() ? n : n - monoStack.top() - 1;
            ans = max(ans, heights[topIndex] * width);
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    vector<int> heights = {2,1,4,3,2,3};
    Solution sol;

    cout << sol.largestRectangleArea(heights) << endl;

    return 0;
}