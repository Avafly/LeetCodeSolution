
// LeetCode Problem:
// Title: Interleaving String
// URL: https://leetcode.com/problems/interleaving-string/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 Idea: dynamic programming
 dp[i][j] indicates whether the first i chars of s1 and the first j chars of
 s2 can form the first i+j chars.
 */

bool isInterleave(char * s1, char * s2, char * s3){
    int s1Size = (int) strlen(s1);
    int s2Size = (int) strlen(s2);
    int s3Size = (int) strlen(s3);

    if(s1Size + s2Size != s3Size) {
        return false;
    }
    
    bool **dp = (bool **)calloc(s1Size + 1, sizeof(bool *));
    for(int i = 0; i <= s1Size; ++i) {
        dp[i] = (bool *)calloc(s2Size + 1, sizeof(bool));
    }
    dp[0][0] = true;

    for(int i = 0; i <= s1Size; ++i) {
        for(int j = 0; j <= s2Size; ++j) {
            if(i > 0) {
                dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            }
            if(j > 0) {
                dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }
    
    bool ans = dp[s1Size][s2Size];
    for(int i = 0; i <= s1Size; ++i) {
        free(dp[i]);
    }
    free(dp);
    
    return ans;
}

int main(int argc, char **argv) {
    char s1[] = "aabcc";
    char s2[] = "dbbca";
    char s3[] = "aadbbcbcac";
    
    printf("%s\n", isInterleave(s1, s2, s3) ? "True" : "False");
    
    return 0;
}
