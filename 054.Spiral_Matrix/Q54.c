#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int h = matrixSize;
    int w = matrixColSize[0];
    int col = w;
    int row = h;
    int i = 0;
    int j = 0;
    int c = 1;
    int index = 0;
    int k;

    int *ans = (int *)malloc(sizeof(int) * (w * h));
    *returnSize = w * h;

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
};

int main(int argc, char **argv) {
    int h = 4;
    int w = 3;

    int **matrix = (int **)malloc(sizeof(int *) * h);
    for(int i = 0; i < h; ++i) {
        matrix[i] = (int *)malloc(sizeof(int) * w);
    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            matrix[i][j] = i * w + j + 1;
        }
    }

    /* print matrix */
    // for(int i = 0; i < h; ++i) {
    //     for(int j = 0; j < w; ++j) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    int matrixColSize[] = {w, w, w, w};
    int *returnSize = (int *)malloc(sizeof(int));

    int *ans = spiralOrder(matrix, h, matrixColSize, returnSize);

    for(int i = 0; i < *returnSize; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    // free
    free(ans);
    for(int i = 0; i < h; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(returnSize);

    return 0;
}