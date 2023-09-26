// LeetCode Problem:
// Title: Longest Substring Without Repeating Characters
// URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SIZE 128

int lengthOfLongestSubstring(char* s) {
    int len = (int) strlen(s);
    if(len == 0) {
        return 0;
    }
    int maxLen = 1;
    int charList[SIZE];

    for(int i = 0; i < len - 1; ++i) {
        // reset the array
        memset(charList, 0, sizeof(charList));

        // mark the char
        ++charList[(int) s[i]];

        for(int j = i + 1; j < len; ++j) {
            int asciiIdx = (int) s[j];
            // a value of 0 means this is first char in substring
            if(charList[asciiIdx] == 0) {
                ++charList[asciiIdx];
                maxLen = MAX(maxLen, j - i + 1);
            }
            else {
                break;
            }
        }
        if(maxLen == len) {
            return maxLen;
        }
    }

    return maxLen;
}

int main(int args, char **argv) {
    char *s = "pwwkew";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}
