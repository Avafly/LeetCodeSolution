
// LeetCode Problem:
// Title: Length of Last Word
// URL: https://leetcode.com/problems/length-of-last-word/

#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char * s){
    
    int n = strlen(s);
    int prevSpace = n;
    int i;

    for(i = n - 1; i >= 0; --i) {
        // skip consecutive spaces
        if(s[i] == ' ') {
            if(prevSpace - i == 1) {
                prevSpace = i;
            }
            else {
                return prevSpace - i - 1;
            }
        }
    }

    return i == -1 ? prevSpace : prevSpace - i - 1;
}

int main(int argc, char **argv) {
    char *s = " aaaaa";

    printf("%d\n", lengthOfLastWord(s));

    return 0;
}