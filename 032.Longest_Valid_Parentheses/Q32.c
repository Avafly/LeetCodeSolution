#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char * s){
    int left = 0;
    int right = 0;
    int ans = 0;

    for(int i = 0; i < strlen(s); ++i) {
        if(s[i] == '(') {
            ++left;
        } else {
            ++right;
        }
        if(left == right) {
            int len = left + right;
            ans = MAX(ans, len);
        }
        if(right > left) {
            left=0;right=0;
        }
    }

    left = 0;
    right = 0;
    for(int i = strlen(s) - 1; i >= 0; --i) {
        if(s[i] == '(') {
            ++left;
        } else {
            ++right;
        }
        if(left == right) {
            int len = left + right;
            ans = MAX(ans,len);
        }
        if(left > right) {
            left = 0;
            right = 0;
        }
    }
    return ans;
}

int main(int argc, char **argv) {

    char *s = "(()";

    printf("%d\n", longestValidParentheses(s));

    return 0;
}