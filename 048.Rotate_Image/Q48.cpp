
// LeetCode Problem:
// Title: Rotate Image
// URL: https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n / 2; ++j) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    sol.rotate(matrix);

    for(auto row : matrix) {
        for(auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}