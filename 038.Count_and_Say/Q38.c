
// LeetCode Problem:
// Title: Count and Say
// URL: https://leetcode.com/problems/count-and-say/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_ANS 5000
#define SIZE_CUR 5000

char *countAndSay(int n) {
    char *ans = (char *)calloc(SIZE_ANS, sizeof(char));
    char *cur = (char *)calloc(SIZE_CUR, sizeof(char));
    ans[0] = '1';
    int ansSize = 1;
    
    for(int i = 2; i <= n; ++i) {
        memset(cur, 0, SIZE_CUR);
        int curSize = 0;
        int count = 1;
        
        for(int j = 1; j < strlen(ans); ++j) {
            if(ans[j] == ans[j - 1]) {
                ++count;
            }
            else {
                int tmp = sprintf(cur + curSize, "%d", count);
                curSize += tmp;
                cur[curSize++] = ans[j - 1];
                count = 1;
            }
        }
        int tmp = sprintf(cur + curSize, "%d", count);
        curSize += tmp;
        cur[curSize++] = ans[ansSize - 1];
        memcpy(ans, cur, curSize);
        ansSize = curSize;
    }
    
    free(cur);
    return ans;
}

int main(int argc, char **argv) {
    int n = 15;
    char *ans = countAndSay(n);
    printf("%s\n", ans);
    free(ans);
    return 0;
}
