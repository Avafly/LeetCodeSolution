#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Idea: same as Q62.
 * However, additional calculations are required due to the presence of obstacles.
 * Here are some special cases:
 * 1. If an obstacle is located at the starting or ending position, the function
 * should return 0.
 * 2. There might be multiple obstacles throughout the grid.
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<long>> map(m, vector<long>(n, 0));
        map[m - 1][n - 1] = 1;

        // find obstacle
        int i = -1, j = -1;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (obstacleGrid[row][col] == 1) {
                    i = row;
                    j = col;
                    map[row][col] = -1;
                }
            }
        }
        // calculate edge's value
        for(int row = m - 2; row >= 0; --row) {
            if(map[row][n - 1] == -1) {
                break;
            }
            map[row][n - 1] = 1;
        }
        for(int col = n - 1; col >= 0; --col) {
            if(map[m - 1][col] == -1) {
                break;
            }
            map[m - 1][col] = 1;
        }

        // if obstacle is located at start point or destination, return 0
        if((i == m - 1 && j == n - 1) || (i == 0 && j == 0)) {
            return 0;
        }

        // same as Q62
        for(int row = m - 2; row >= 0; --row) {
            for(int col = n - 2; col >= 0; --col) {
                if(map[row][col] == -1)  continue;
                map[row][col] = max(0L, map[row][col + 1]) + max(0L, map[row + 1][col]);
            }
        }

        return max(0L, map[0][0]);
    }
};

int main(int argc, char **argv) {

    vector<vector<int>> obstacleGrid(3, vector<int>(2, 0));
    obstacleGrid[1][0] = 1;
    obstacleGrid[1][1] = 1;

    Solution sol = Solution();

    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}