#include <stdio.h>

/**
 * Idea: Dynamic programming
 * map[row][col] represents the possible unique paths to reach map[m - 1][n - 1]
 * from that position. map[row][col] represents the possible unique paths to
 * reach map[m - 1][n - 1] from that position.
 * Therefore, map[row][col] = map[row + 1][col] + map[row][col + 1]. Since the
 * positions on the rightmost and bottom edge of the map can only move down or
 * right, the map is initialized as follows:
 * 0 0 0 0 0 0 1
 * 0 0 0 0 0 0 1
 * 1 1 1 1 1 1 1
 */

int uniquePaths(int m, int n){
    int map[m][n];

    for(int row = 0; row < m; ++row) {
        map[row][n - 1] = 1;
    }
    for(int col = 0; col < n; ++col) {
        map[m - 1][col] = 1;
    }

    for(int row = m - 2; row >= 0; --row) {
        for(int col = n - 2; col >= 0; --col) {
            map[row][col] = map[row][col + 1] + map[row + 1][col];
        }
    }

    return map[0][0];
}

int main(int argc, char **argv) {
    int m = 3;
    int n = 7;

    printf("%d\n", uniquePaths(m, n));

    return 0;
}