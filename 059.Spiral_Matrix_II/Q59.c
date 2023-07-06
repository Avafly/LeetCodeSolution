#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    int **matrix = (int **)malloc(sizeof(int *) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = n;
    }
    for(int i = 0; i < *returnSize; ++i) {
        matrix[i] = (int *)malloc(sizeof(int) * (*returnColumnSizes)[i]);
    }

    
    int count = 0;
    int col = n;
    int row = n;
    int i = 0;
    int j = 0;
    int c = 1;
    int k;

    while(row > 0 && col > 0) {
        switch(c) {
            case 1:
                c = 2;
                for(k = 0; k < col; ++k) {
                    matrix[i][j + k] = ++count;
                }
                j = j + k - 1;
                ++i;
                --row;
                break;

            case 2:
                c = 3;
                for(k = 0; k < row; ++k) {
                    matrix[i + k][j] = ++count;;
                }
                i = i + k - 1;
                --j;
                --col;
                break;

            case 3:
                c = 4;
                for(k = 0; k < col; ++k) {
                    matrix[i][j - k] = ++count;;
                }
                j = j - k + 1;
                --i;
                --row;
                break;

            case 4:
                c = 1;
                for(k = 0; k < row; ++k) {
                    matrix[i - k][j] = ++count;;
                }
                i = i - k + 1;
                ++j;
                --col;
                break;

            default:
                break;
        }
    }

    return matrix;
}

int main(int argc, char **argv) {

    int n = 5;
    int *returnSize = (int *)malloc(sizeof(int));
    int *returnColumnSizes = NULL;

    int **ans = generateMatrix(n, returnSize, &returnColumnSizes);

    for(int i = 0; i < *returnSize; ++i) {
        for(int j = 0; j < *returnSize; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }


    /* deallocate the memory */
    for(int i = 0; i < *returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
    free(returnSize);
    return 0;
}