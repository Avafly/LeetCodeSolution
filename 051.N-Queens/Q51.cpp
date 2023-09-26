
// LeetCode Problem:
// Title: N-Queens
// URL: https://leetcode.com/problems/n-queens/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        rec(ans, board, 0, n);
        return ans;
    }

private:
    void rec(vector<vector<string>> &ans, vector<string> &board, int row, int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; ++col) {
            if(isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                rec(ans, board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }

    bool isValid(const vector<string> &board, int row, int col, int n) {
        for(int i = 0; i < row; ++i) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    int n = 4;
    vector<vector<string>> ans = sol.solveNQueens(n);

    for(auto &entry : ans) {
        for(auto &str : entry) {
            cout << str << endl;
        }
        cout << "---" << endl;
    }

    return 0;
}