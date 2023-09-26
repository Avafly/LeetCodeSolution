
// LeetCode Problem:
// Title: Search a 2D Matrix
// URL: https://leetcode.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int l = 0;
        int r = rowSize * colSize - 1;
        

        while(l <= r) {
            int mid = l + (r - l) / 2;
            int row = mid / colSize;
            int col = mid % colSize;
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][col] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return false;
    }
};

int main(int argc, char **argv) {
    Solution sol;

    int target = 3;

    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60},
    };

    cout << (sol.searchMatrix(matrix, target) ? "True" : "False") << endl;

    return 0;
}
