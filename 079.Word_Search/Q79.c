#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
 Idea: backtrace
 */

bool rec(char **board, int boardSize, int *boardColSize, const char *word, int row, int col) {
    if(*word == '\0') {
        return true;
    }

    if(row < 0 || row >= boardSize) {
        return false;
    }
    if(col < 0 || col >= boardColSize[0]) {
        return false;
    }
    if(board[row][col] != *word) {
        return false;
    }
    
    char tmp = *word;
    board[row][col] = '.';
    // up
    if(rec(board, boardSize, boardColSize, word + 1, row - 1, col)) {
        return true;
    }
    // down
    if(rec(board, boardSize, boardColSize, word + 1, row + 1, col)) {
        return true;
    }
    // left
    if(rec(board, boardSize, boardColSize, word + 1, row, col - 1)) {
        return true;
    }
    // right
    if(rec(board, boardSize, boardColSize, word + 1, row, col + 1)) {
        return true;
    }
    board[row][col] = tmp;
    
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    if(strlen(word) > boardSize * boardColSize[0])   return false;
    
    for(int row = 0; row < boardSize; ++row) {
        for(int col = 0; col < boardColSize[row]; ++col) {
            if(rec(board, boardSize, boardColSize, word, row, col)) {
                return true;
            }
        }
    }
    
    return false;
}

int main(int argc, char **argv) {
    char boardData[][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    int boardSize = (int)(sizeof(boardData) / sizeof(boardData[0]));
    int boardColSize[] = {4, 4, 4};
    char **board = (char **)malloc(sizeof(char *) * boardSize);
    for(int i = 0; i < boardSize; ++i) {
        board[i] = (char *)malloc(sizeof(char) * boardColSize[i]);
        memcpy(board[i], boardData[i], sizeof(char) * boardColSize[i]);
    }
    char *word = "SEE";
    
    // print board
//    for(int i = 0; i < boardSize; ++i) {
//        for(int j = 0; j < boardColSize[i]; ++j) {
//            printf("%c ", board[i][j]);
//        }
//        printf("\n");
//    }
    
    printf("%s\n", exist(board, boardSize, boardColSize, word) ? "Ture" : "False");
    
    /* free the memory */
    for(int i = 0; i < boardSize; ++i) {
        free(board[i]);
    }
    free(board);
    return 0;
}