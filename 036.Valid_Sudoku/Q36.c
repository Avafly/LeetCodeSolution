#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int boxes[9][9] = {0};

    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            int boxIndex = (i / 3) * 3 + j / 3;

            // char number to int number
            // minus 1 for index: 1~9 -> 0~8
            int cellValue = board[i][j] - '0' - 1;
            // ignore '.'
            if(cellValue < 0) continue;

            if(rows[i][cellValue] != 0 || cols[j][cellValue] != 0 || boxes[boxIndex][cellValue] != 0) {
                return false;
            }

            ++rows[i][cellValue];
            ++cols[j][cellValue];
            ++boxes[boxIndex][cellValue];
        }
    }

    return true;
}

int main(int argc, char **argv) {
    char *board1[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    char *board2[9] = {
        "83..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    int boardColSize[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};

    printf("%s\n", isValidSudoku(board1, 9, boardColSize) ? "True" : "False");
    return 0;
}