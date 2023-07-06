#include <iostream>
#include <vector>
using namespace std;

/*
 Idea: backtrace
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int height = static_cast<int>(board.size()), width = static_cast<int>(board[0].size());
        if(word.size() > height * width)    return false;

        for(int row = 0; row < height; ++row) {
            for(int col = 0; col < width; ++col) {
                if(board[row][col] == word[0]) {
                    if(rec(board, word, 0, row, col)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
private:
    bool rec(vector<vector<char>> &board, string &word, int index, int row, int col) {
        if(index >= word.size()) {
            return true;
        }
        if(row < 0 || row >= board.size()) {
            return false;
        }
        if(col < 0 || col >= board[0].size()) {
            return false;
        }
        if(board[row][col] != word[index]) {
            return false;
        }
        
        char tmp = word[index];
        board[row][col] = '.';
        // up
        if(rec(board, word, index + 1, row - 1, col)) {
            return true;
        }
        // down
        if(rec(board, word, index + 1, row + 1, col)) {
            return true;
        }
        // left
        if(rec(board, word, index + 1, row, col - 1)) {
            return true;
        }
        // right
        if(rec(board, word, index + 1, row, col + 1)) {
            return true;
        }
        
        board[row][col] = tmp;
        
        return false;
    }
};

int main(int argc, char **argv) {
    vector<vector<char>> board = {
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
    };
    string word = "AAAAAAAAAAAAAAB";
    
    Solution sol;
    
    cout << (sol.exist(board, word) ? "True" : "False") << endl;
    
    return 0;
}