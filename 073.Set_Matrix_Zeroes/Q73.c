#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    bool isRowZero = false;
    bool isColZero = false;
    
    for(int row = 0; row < matrixSize; ++row) {
        if(matrix[row][0] == 0) {
            isRowZero = true;
            break;
        }
    }
    for(int col = 0; col < matrixColSize[0]; ++col) {
        if(matrix[0][col] == 0) {
            isColZero = true;
            break;
        }
    }

    for(int row = 1; row < matrixSize; ++row) {
        for(int col = 1; col < matrixColSize[0]; ++col) {
            if(matrix[row][col] == 0) {
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }

    for(int row = 1; row < matrixSize; ++row) {
        if(matrix[row][0] == 0) {
            for(int i = 0; i < matrixColSize[0]; ++i) {
                matrix[row][i] = 0;
            }
        }
    }
    for(int col = 1; col < matrixColSize[0]; ++col) {
        if(matrix[0][col] == 0) {
            for(int i = 0; i < matrixSize; ++i) {
                matrix[i][col] = 0;
            }
        }
    }

    if(isRowZero) {
        for(int i = 0; i < matrixSize; ++i) {
            matrix[i][0] = 0;
        }
    }
    if(isColZero) {
        for(int i = 0; i < matrixColSize[0]; ++i) {
            matrix[0][i] = 0;
        }
    }
}

int main() {
    int matrixData[][3] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    int matrixSize = sizeof(matrixData) / sizeof(matrixData[0]);
    int matrixColSize[] = {3, 3, 3, 3};
    int **matrix = (int **)malloc(matrixSize * sizeof(int *));
    for(int i = 0; i < matrixSize; ++i) {
        matrix[i] = (int *)malloc(matrixColSize[i] * sizeof(int));
        for(int j = 0; j < matrixColSize[i]; ++j) {
            matrix[i][j] = matrixData[i][j];
        }
    }

    setZeroes(matrix, matrixSize, matrixColSize);

    // print matrix
    for(int i = 0; i < matrixSize; ++i) {
        for(int j = 0; j < matrixColSize[i]; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // free memory
    for(int i = 0; i < matrixSize; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
