#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int totalNQueens(int n) {
    int size[] = {1, 0, 0, 2, 10, 4, 40, 92, 352};
    return size[n - 1];
}

bool isValid(char **board, int row, int col, int n) {
    for(int i = 0; i < row; ++i) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void rec(char ***ans, char **board, int row, int n, int *count) {
    if(row == n) {
        /* apeend the board */
        ans[*count] = (char **)malloc(sizeof(char *) * n);
        for(int i = 0; i < n; ++i) {
            ans[*count][i] = (char *)calloc(n + 1, sizeof(char));
            strcpy(ans[*count][i], board[i]);
        }
        ++(*count);
        return;
    }

    for(int col = 0; col < n; ++col) {
        if(isValid(board, row, col, n)) {
            board[row][col] = 'Q';
            rec(ans, board, row + 1, n, count);
            board[row][col] = '.';
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = totalNQueens(n);

    int *count = (int *)calloc(1, sizeof(int));
    char ***ans = (char ***)malloc(sizeof(char **) * (*returnSize));
    char **board = (char **)malloc(sizeof(char *) * n);
    for(int i = 0; i < n; ++i) {
        board[i] = (char *)calloc(n + 1, sizeof(char));
        for(int j = 0; j < n; ++j) {
            board[i][j] = '.';
        }
    }

    rec(ans, board, 0, n, count);

    /* create returnColumnSizes */
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = n;
    }

    /* free the memory */
    for(int i = 0; i < n; ++i) {
        free(board[i]);
    }
    free(board);
    free(count);

    return ans;
}

int main(int argc, char **argv) {

    int n = 9;
    int *returnSize = (int *)malloc(sizeof(int));
    int *returnColumnSizes = NULL;

    char ***ans = solveNQueens(n, returnSize, &returnColumnSizes);

    /* print the answer */
    for(int i = 0; i < *returnSize; ++i) {
        for(int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%s\n",  ans[i][j]);
        }
        printf("---------\n");
    }

    /* free the memory */
    for(int i = 0; i < *returnSize; ++i) {
        for(int j = 0; j < (*returnColumnSizes); ++j) {
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
    free(returnSize);
    return 0;
}