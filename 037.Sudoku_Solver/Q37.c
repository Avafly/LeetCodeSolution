#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solve(char **board);
bool isValid(char **board, int row, int col, char numc);

void solveSudoku(char** board, int boardSize, int* boardColSize){
    solve(board);
}

bool solve(char **board) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(board[i][j] == '.') {
                for(char numc = '1'; numc <= '9'; ++numc) {
                    if(isValid(board, i, j, numc)) {
                        board[i][j] = numc;

                        if(solve(board)) {
                            return true;
                        }
                        
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isValid(char **board, int row, int col, char numc) {
    for(int i = 0; i < 9; ++i) {
        if(board[row][i] == numc)   return false;
        if(board[i][col] == numc)   return false;
        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == numc) return false;
    }
    return true;
}

int main(int argc, char **argv) {

    // create board
    char **board = (char**)malloc(9 * sizeof(char*));
    for(int i = 0; i < 9; ++i) {
        board[i] = (char*)malloc(10 * sizeof(char));
        //memset(board[i], '\0', sizeof(board[i]));
    }
    strcpy(board[0], "53..7....");
    strcpy(board[1], "6..195...");
    strcpy(board[2], ".98....6.");
    strcpy(board[3], "8...6...3");
    strcpy(board[4], "4..8.3..1");
    strcpy(board[5], "7...2...6");
    strcpy(board[6], ".6....28.");
    strcpy(board[7], "...419..5");
    strcpy(board[8], "....8..79");

    int boardColSize[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};

    solveSudoku(board, 9, boardSize);

    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            printf("%c ", board[i][j]);
        }
        free(board[i]);
        printf("\n");
    }
    free(board);

    return 0;
}