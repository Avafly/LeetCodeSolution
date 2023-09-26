
// LeetCode Problem:
// Title: Edit Distance
// URL: https://leetcode.com/problems/edit-distance/

#include <stdio.h>
#include <string.h>

/*
 * Idea: Levenshtein Distance
 */

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int minDistance(char * word1, char * word2){
    int width = strlen(word1);
    int height = strlen(word2);
    int table[height + 1][width + 1];

    for(int row = 0; row < height + 1; ++row) {
        for(int col = 0; col < width + 1; ++col) {
            if(row == 0) {
                table[row][col] = col;
            }
            else if(col == 0) {
                table[row][col] = row;
            }
            else if(word1[col - 1] == word2[row - 1]) {
                table[row][col] = table[row - 1][col - 1];
            }
            else {
                table[row][col] = MIN3(table[row - 1][col - 1], table[row - 1][col], table[row][col - 1]) + 1;
            }
        }
    }

    return table[height][width];
}

int main(int argc, char **argv) {
    char *word1 = "horse";
    char *word2 = "ros";

    printf("%d\n", minDistance(word1, word2));

    return 0;
}