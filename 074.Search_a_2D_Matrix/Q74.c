
// LeetCode Problem:
// Title: Search a 2D Matrix
// URL: https://leetcode.com/problems/search-a-2d-matrix/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target){
    int l = 0;
    int r = matrixSize * matrixColSize[0] - 1;

    while(l <= r) {
        int mid = l + (r - l) / 2;
        int row = mid / matrixColSize[0];
        int col = mid % matrixColSize[0];
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) l = mid + 1;
        else r = mid - 1;
    }
    
    return false;
}

int main(int argc, char **argv) {
    int matrixData[][4] = {
        {1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,60},
    };
    int matrixSize = sizeof(matrixData) / sizeof(matrixData[0]);
    int matrixColSize[] = {4, 4, 4};
    int **matrix = (int **)malloc(sizeof(int *) * matrixSize);
    for(int i = 0; i < matrixSize; ++i) {
        matrix[i] = (int *)malloc(sizeof(int) * matrixColSize[0]);
        for(int j = 0; j < matrixColSize[0]; ++j) {
            matrix[i][j] = matrixData[i][j];
        }
    }
    int target = 3;

    printf("%s\n", searchMatrix(matrix, matrixSize, matrixColSize, target) ? "True" : "False");

    /* free the memory */
    for(int i = 0; i < matrixSize; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}