#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int h = matrix.size();
        int w = matrix[0].size();
        int col = w;
        int row = h;
        int i = 0;
        int j = 0;
        int c = 1;
        int index = 0;
        int k;

        vector<int> ans(h * w, 0);

        if(w == 1) {
            for(int i = 0; i < h; ++i) {
                ans[i] = matrix[i][0];
            }
            return ans;
        }

        while(row > 0 && col > 0) {
            switch(c) {
                case 1:
                    c = 2;
                    for(k = 0; k < col; ++k) {
                        ans[index++] = matrix[i][j + k];
                    }
                    j = j + k - 1;
                    ++i;
                    --row;
                    break;

                case 2:
                    c = 3;
                    for(k = 0; k < row; ++k) {
                        ans[index++] = matrix[i + k][j];
                    }
                    i = i + k - 1;
                    --j;
                    --col;
                    break;

                case 3:
                    c = 4;
                    for(k = 0; k < col; ++k) {
                        ans[index++] = matrix[i][j - k];
                    }
                    j = j - k + 1;
                    --i;
                    --row;
                    break;

                case 4:
                    c = 1;
                    for(k = 0; k < row; ++k) {
                        ans[index++] = matrix[i - k][j];
                    }
                    i = i - k + 1;
                    ++j;
                    --col;
                    break;

                default:
                    break;
            }
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    vector<int> ans = sol.spiralOrder(matrix);

    for(auto &num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}