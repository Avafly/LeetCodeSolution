// LeetCode Problem:
// Title: String to Integer (atoi)
// URL: https://leetcode.com/problems/string-to-integer-atoi/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myAtoi(char* s) {
    int len = strlen(s);

    int flag = 1;
    long long num = 0;
    int start = 0;
    int end = 0;
    int bound = 0;
    int zeroflag = 1;

    for (int i=0; i<len; ++i) {
        // if flag=1, space, plus, minus chars are acceptable
        if (flag == 1) {
            if (s[i]==' ') {
                ++start;
                //++end;
                continue;
            }
            else if (s[i]=='+' || s[i]=='-') {
                ++bound;
                ++end;
                flag = 0;
                continue;
            }
            // neither a space nor a sign or a number char
            else if (isdigit(s[i])==0) {
                return 0;
            }
            else {
                flag = 0;
            }
        }
        // if flag=0, only digit chars are acceptable
        if (flag == 0) {
            if (isdigit(s[i])==0) {
                break;
            }
            ++end;
            // zero char that should be ignore
            if (zeroflag == 1 && s[i] == '0') {
                continue;
            }
            zeroflag = 0;
            ++bound;
            if (bound > 11) {
                break;
            }
        }
    }

    // empty char
    if (end == 0)
        return 0;
    // only one char and not a digit char
    if (end == 1 && (s[0]=='+' || s[0]=='-'))
        return 0;

    char* ss = s + start;

    char numStr[end+1];
    memcpy(numStr, ss, end);
    numStr[end] = '\0';

    num = atoll(numStr);
    if (num < -2147483648)
        return -2147483648;
    else if (num > 2147483647)
        return 2147483647;

    return num;


    return len;
}

int main(int argc, char **argv) {

    char *s = "42";

    printf("%d\n", myAtoi(s));

    return 0;
}
