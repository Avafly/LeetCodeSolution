
// LeetCode Problem:
// Title: Spiral Matrix II
// URL: https://leetcode.com/problems/spiral-matrix-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 1));
        int count = 0;
        int col = n, row = n;
        int i = 0, j = 0;
        int c = 1, k;

        while(row > 0 && col > 0) {
            switch(c) {
                case 1:
                    c = 2;
                    for(k = 0; k < col; ++k) {
                        matrix[i][j + k] = ++count;
                    }
                    j = j + k - 1;
                    ++i;
                    --row;
                    break;

                case 2:
                    c = 3;
                    for(k = 0; k < row; ++k) {
                        matrix[i + k][j] = ++count;;
                    }
                    i = i + k - 1;
                    --j;
                    --col;
                    break;

                case 3:
                    c = 4;
                    for(k = 0; k < col; ++k) {
                        matrix[i][j - k] = ++count;;
                    }
                    j = j - k + 1;
                    --i;
                    --row;
                    break;

                case 4:
                    c = 1;
                    for(k = 0; k < row; ++k) {
                        matrix[i - k][j] = ++count;;
                    }
                    i = i - k + 1;
                    ++j;
                    --col;
                    break;

                default:
                    break;
            }
        }

        return matrix;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();
    int n = 3;

    vector<vector<int>> ans = sol.generateMatrix(n);

    for(auto &vec : ans) {
        for(auto &num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}