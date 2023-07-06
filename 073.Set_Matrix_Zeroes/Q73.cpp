#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isRowZero = false;
        bool isColZero = false;

        for(int row = 0; row < matrix.size(); ++row) {
            if(matrix[row][0] == 0) {
                isRowZero = true;
                break;
            }
        }
        for(int col = 0; col < matrix[0].size(); ++col) {
            if(matrix[0][col] == 0) {
                isColZero = true;
                break;
            }
        }

        for(int row = 1; row < matrix.size(); ++row) {
            for(int col = 1; col < matrix[0].size(); ++col) {
                if(matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for(int row = 1; row < matrix.size(); ++row) {
            if(matrix[row][0] == 0) {
                for(int i = 0; i < matrix[0].size(); ++i) {
                    matrix[row][i] = 0;
                }
            }
        }
        for(int col = 1; col < matrix[0].size(); ++col) {
            if(matrix[0][col] == 0) {
                for(int i = 0; i < matrix.size(); ++i) {
                    matrix[i][col] = 0;
                }
            }
        }

        if(isRowZero) {
            for(int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
        if(isColZero) {
            for(int i = 0; i < matrix[0].size(); ++i) {
                matrix[0][i] = 0;
            }
        }

    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    sol.setZeroes(matrix);

    for(auto &row : matrix) {
        for(auto &num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}