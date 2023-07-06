#include <stdio.h>
#include <stdlib.h>

void swap(int *l, int *r){
    // if l == r, the XOR-based swap will set the value to zero
    if(*l != *r) {
        *l = *l ^ *r;
        *r = *r ^ *l;
        *l = *l ^ *r;
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    // transpose
    for(int i = 0; i < matrixSize; ++i) {
        for(int j = i; j < matrixSize; ++j) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }

    // reverse
    for(int i = 0; i < matrixSize; ++i) {
        for(int j = 0; j < matrixSize / 2; ++j) {
            swap(&matrix[i][j], &matrix[i][matrixSize - 1 - j]);
        }
    }
}

int main(int argc, char **argv) {
    int matrixSize = 3;
    int matrixColSize[] = {3, 3, 3};

    int **matrix = (int **)malloc(sizeof(int *) * matrixSize);
    matrix[0] = (int *)malloc(sizeof(int) * matrixColSize[0]);
    matrix[1] = (int *)malloc(sizeof(int) * matrixColSize[1]);
    matrix[2] = (int *)malloc(sizeof(int) * matrixColSize[2]);

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    rotate(matrix, matrixSize, matrixColSize);

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < matrixSize; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}