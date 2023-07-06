#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // calculate values of the leftmost edge of the map
        for(int row = 1; row < m; ++row) {
            grid[row][0] = grid[row][0] + grid[row - 1][0];
        }
        // calculate top values of the map
        for(int col = 1; col < n; ++col) {
            grid[0][col] = grid[0][col] + grid[0][col - 1];
        }
        
        for(int row = 1; row < m; ++row) {
            for(int col = 1; col < n; ++col) {
                grid[row][col] = grid[row][col] + min(grid[row - 1][col], grid[row][col - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main(int argc, char **argv) {

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };

    Solution sol = Solution();

    cout << sol.minPathSum(grid) << endl;

    return 0;
}