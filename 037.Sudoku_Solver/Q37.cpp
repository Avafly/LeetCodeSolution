#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    for(char num = '1'; num <= '9'; ++num) {
                        if(isValid(board, i, j, num)) {
                            board[i][j] = num;

                            if(solve(board)) {
                                return true;
                            }

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for(int i = 0; i < 9; ++i) {
            if(board[i][col] == num)    return false; // check column
            if(board[row][i] == num)    return false; // check row
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)  return false; // check 3x3 box
        }
        return true;
    }
};



int main(int argc, char **argv) {

    Solution sol = Solution();

    // input1
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
    // input2
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

    vector<vector<char>> board = board1;

    sol.solveSudoku(board);

    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}