#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 Idea
 For each cell in the matrix, if its value is '1', calculate and store the
 number of consecutive '1's immediately above it, including itself. If its
 value is '0', store '0' for that cell.
 Then, treat the preprocessed values as histogram heights and find the
 largest rectangle in the histogram (as Leetcode problem 84).
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(), 0);
        int ans = 0;
        
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == '0') {
                    heights[j] = 0;
                }
                else {
                    heights[j] += 1;
                }
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        
        return ans;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
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
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };

    Solution sol;
    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}