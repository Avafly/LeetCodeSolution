
// LeetCode Problem:
// Title: Minimum Path Sum
// URL: https://leetcode.com/problems/minimum-path-sum/

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minPathSum(int **grid, int gridSize, int *gridColSize){
    int m = gridSize;
    int n = gridColSize[0];

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
            grid[row][col] = grid[row][col] + MIN(grid[row - 1][col], grid[row][col - 1]);
        }
    }

    return grid[m - 1][n - 1];
}

int main(int argc, char **argv) {
    int nums[][3] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };
    int m = sizeof(nums) / sizeof(nums[0]);
    int n = sizeof(nums[0]) / sizeof(int);

    // create grid and its parameters
    int gridSize = m;
    int *gridColSize = (int *)calloc(gridSize, sizeof(int));
    int **grid = (int **)calloc(gridSize, sizeof(int *));
    for(int i = 0; i < m; ++i) {
        grid[i] = (int *)calloc(n, sizeof(int));
        gridColSize[i] = n;
        for(int j = 0; j < n; ++j) {
            grid[i][j] = nums[i][j];
        }
    }

    printf("%d\n", minPathSum(grid, gridSize, gridColSize));

    // free the memory
    for(int i = 0; i < m; ++i) {
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);
    return 0;
}