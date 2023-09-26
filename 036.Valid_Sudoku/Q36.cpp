
// LeetCode Problem:
// Title: Valid Sudoku
// URL: https://leetcode.com/problems/valid-sudoku/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                char cellValue = board[i][j];
                if(cellValue == '.') continue;

                int boxIndex = (i / 3) * 3 + j / 3;

                // check for duplicates in row, column, and box
                if(rows[i].count(cellValue) || cols[j].count(cellValue) || boxes[boxIndex].count(cellValue)) {
                    return false;
                }

                // add value to row, column, and box sets
                rows[i].insert(cellValue);
                cols[j].insert(cellValue);
                boxes[boxIndex].insert(cellValue);
            }
        }

        return true;
    }
};


int main(int argc, char **argv) {

    Solution sol = Solution();

    // sudoku's input 1
    vector<vector<char>> board1 =
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},        
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    // sudoku's input 2
    vector<vector<char>> board2 =
    {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    cout << ((true==sol.isValidSudoku(board1)) ? "True" : "False") << endl;

    return 0;
}