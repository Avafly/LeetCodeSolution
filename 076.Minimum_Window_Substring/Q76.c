#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/*
 Idea: double pointers
 */

char * minWindow(char * s, char * t){
    if(strlen(t) > strlen(s))   return "";
    int count_s[58] = {0};
    int count_t[58] = {0};
    int l = 0, r = 0;
    int minLen = INT_MAX;
    int char_n = 0;
    int uniq_char = 0;
    int start = 0;
    
    /* count t's chars */
    for(int i = 0; i < strlen(t); ++i) {
        if(count_t[t[i] - 'A'] == 0) {
            ++uniq_char;
        }
        ++count_t[t[i] - 'A'];
    }
    
    /* double pointers */
    while(l < strlen(s) && r < strlen(s)) {
        // right pointer
        for(; r < strlen(s); ++r) {
            if(strchr(t, s[r])) {
                ++count_s[s[r] - 'A'];
                if(count_s[s[r] - 'A'] == count_t[s[r] - 'A']) {
                    if(char_n < uniq_char) {
                        ++char_n;
                    }
                }
                if(char_n >= uniq_char) {
                    break;
                }
            }
        }
        // check if all chars in t appear in s
        if(char_n < uniq_char) {
            return "";
        }
        // left pointer
        for(; l < strlen(s); ++l) {
            if(strchr(t, s[l])) {  // if s[l] is in t
                // move l to right as far as possible while containing all chars in t
                if(count_s[s[l] - 'A'] == count_t[s[l] - 'A']) {
                    if(r - l + 1 < minLen) {
                        start = l;
                        minLen = r - l + 1;
                    }
                    break;
                }
                else {
                    --count_s[s[l] - 'A'];
                }
            }
        }
        ++r;
    }
    
    char *ans = (char *)calloc(minLen + 1, sizeof(char));
    strncpy(ans, s + start, minLen);
    ans[minLen] = '\0';
    return ans;
}

int main(int argc, char **argv) {
    char *s = "cabwefgewcwaefgcf";
    char *t = "cae";
    
    char *ans = minWindow(s, t);
    printf("%s\n", ans);
    
    free(ans);
    return 0;
}
