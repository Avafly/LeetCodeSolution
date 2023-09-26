
// LeetCode Problem:
// Title: Longest Common Prefix
// URL: https://leetcode.com/problems/longest-common-prefix/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestCommonPrefix(char **strs, int strsSize) {
    if(strsSize == 0) {
        return "";
    }
    if(strsSize == 1) {
        return strs[0];
    }

    char *prefix = (char *)calloc(strlen(strs[0]) + 1, sizeof(char));
    int count = 0;
    int i;

    while(strs[0][count] != '\0') {
        for(i = 1; i < strsSize; ++i) {
            if(strs[0][count] != strs[i][count]) {
                break;
            }
        }

        if(i == strsSize) {
            prefix[count] = strs[0][count];
            ++count;
        }
        else {
            break;
        }
    }
    prefix[count] = '\0';
    return prefix;
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Wrong input!\n");
    }
    else {
        char *ans = longestCommonPrefix(argv + 1, argc - 1);
        printf("%s\n", ans);
        free(ans);
    }
    return 0;
}
