
// LeetCode Problem:
// Title: Decode Ways
// URL: https://leetcode.com/problems/decode-ways/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numDecodings(char * s){
    if(s[0] == '0') return 0;
    
    int sSize = (int)strlen(s);
    int *dp = (int *)calloc(sSize + 1, sizeof(int));
    char twoDigits[3];
    twoDigits[2] = '\0';
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= sSize; ++i) {
        if(s[i - 1] != '0') dp[i] += dp[i - 1];
        strncpy(twoDigits, s + i - 2, 2);
        if(10 <= atoi(twoDigits) && atoi(twoDigits) <= 26) dp[i] += dp[i - 2];
    }
    
    int ans = dp[sSize];
    free(dp);
    return ans;
}

int main(int argc, char **argv) {
    char *s = "111111111111111";
    printf("%d\n", numDecodings(s));
    
    return 0;
}
