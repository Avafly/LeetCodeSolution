#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rec(char **ans, int left, int right, int n, char *per, int perIndex, int *count) {
    if(left == n && right == n) {
        // append string to answer
        ans[*count] = (char *)calloc(2 * n + 1, sizeof(char));
        for(int i = 0; i < 2 * n; ++i) {
            ans[*count][i] = per[i];
        }
        ++(*count);
        return;
    }
    if(left < n) {
        per[perIndex] = '(';
        rec(ans, left + 1, right, n, per, perIndex + 1, count);
    }
    if(right < n && left > right) {
        per[perIndex] = ')';
        rec(ans, left, right + 1, n, per, perIndex + 1, count);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    int MAXSIZE[] = {0, 1, 2, 5, 14, 42, 132, 429, 1430};
    *returnSize = MAXSIZE[n];
    char **ans = (char **)calloc(*returnSize + 1, sizeof(char *));
    
    int *count = (int *)calloc(1, sizeof(int));
    char *per = (char *)calloc(2 * n + 1, sizeof(char));

    rec(ans, 0, 0, n, per, 0, count);

    free(per);
    free(count);
    return ans;
}

int main(int argc, char **argv) {
    
    int n = 5;
    int *returnSize = (int *)malloc(sizeof(int));

    char **ans = generateParenthesis(n, returnSize);

    for(int i = 0; i < *returnSize; ++i) {
        for(int j = 0; j < 2 * n; ++j) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }

    /* free the memory */
    for(int i = 0; i < *returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnSize);
    return 0;
}