
// LeetCode Problem:
// Title: Unique Paths II
// URL: https://leetcode.com/problems/unique-paths-ii/

#include <stdio.h>
#include <stdlib.h>

/**
 * Idea: same as Q62.
 * However, additional calculations are required due to the presence of obstacles.
 * Here are some special cases:
 * 1. If an obstacle is located at the starting or ending position, the function
 * should return 0.
 * 2. There might be multiple obstacles throughout the grid.
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];

    long **map = (long **)calloc(m, sizeof(long *));
    for(int i = 0; i < obstacleGridSize; ++i) {
        map[i] = (long *)calloc(n, sizeof(long));
    }
    map[m - 1][n - 1] = 1;

    // find obstacle
    int i = -1;
    int j = -1;

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

    // if obstacle is located at start or end point, return 0
    if((i == m - 1 && j == n - 1) || (i == 0 && j == 0)) {
        return 0;
    }

    // same as Q62
    for(int row = m - 2; row >= 0; --row) {
        for(int col = n - 2; col >= 0; --col) {
            if(map[row][col] == -1)  continue;
            map[row][col] = MAX(0L, map[row][col + 1]) + MAX(0L, map[row + 1][col]);
        }
    }

    long ans = map[0][0];
    // free the memory
    for(int i = 0; i < obstacleGridSize; ++i) {
        free(map[i]);
    }
    free(map);

    return MAX(0L, ans);
}

int main(int argc, char **argv) {
    int grid[][2] = {
        {0, 0},
        {1, 1},
        {0, 0},
    };
    int obstacleGridSize = sizeof(grid) / sizeof(grid[0]);
    int colSize = sizeof(grid[0]) / sizeof(int);
    int obstacleGridColSize[] = {colSize, colSize, colSize};
    int **obstacleGrid = (int **)malloc(sizeof(int *) * obstacleGridSize);
    for(int i = 0; i < obstacleGridSize; ++i) {
        obstacleGrid[i] = (int *)malloc(sizeof(int) * obstacleGridColSize[i]);
        for(int j = 0; j < obstacleGridColSize[i]; ++j) {
            obstacleGrid[i][j] = grid[i][j];
        }
    }

    printf("%d\n", uniquePathsWithObstacles(obstacleGrid, obstacleGridSize, obstacleGridColSize));

    // free the memory
    for(int i = 0; i < obstacleGridSize; ++i) {
        free(obstacleGrid[i]);
    }
    free(obstacleGrid);
    return 0;
}