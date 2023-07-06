#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 260

void rec(char **ans, int *ansSize, char **char_table, char *digits, char *comb, int *combSize) {
    if(strlen(digits) == 0) {
        ans[(*ansSize)++] = strdup(comb);
        return;
    }
    
    for(int i = 0; i < strlen(char_table[digits[0] - '0']); ++i) {
        comb[(*combSize)++] = (char_table[digits[0] - '0'])[i];
        rec(ans, ansSize, char_table, digits + 1, comb, combSize);
        --(*combSize);
    }

    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char * digits, int* returnSize){
    if(strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    char *char_table[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    char *comb = (char *)calloc(strlen(digits) + 1, sizeof(char));
    char **ans = (char **)malloc(SIZE * sizeof(char *));
    int *combSize = (int *)calloc(1, sizeof(int));
    int *ansSize = (int *)calloc(1, sizeof(int));

    rec(ans, ansSize, char_table, digits, comb, combSize);
    *returnSize = *ansSize;
    
    free(comb);
    free(combSize);
    free(ansSize);
    
    return ans;
}

int main(int argc, char **argv) {

    char *digits = "";
    int returnSize;

    char **ans = letterCombinations(digits, &returnSize);
    
    for(int i = 0; i < returnSize; ++i) {
        printf("%s\n", ans[i]);
    }

    // free memory
    for(int i = 0; i < returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);

    return 0;
}
