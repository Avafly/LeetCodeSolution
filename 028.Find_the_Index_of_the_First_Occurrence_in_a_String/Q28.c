#include <stdio.h>
#include <string.h>



int strStr(char * haystack, char * needle){
    int len1 = strlen(haystack);
    int len2 = strlen(needle);

    int prevI = 0;
    int nextI = 0;
    int isMark = 0;
    int j = 0;
    for(int i=0; i<strlen(haystack); ++i) {
        if(haystack[i] == needle[j]) {
            if(j == len2-1) {
                return i - j;
            }
            if(!isMark && haystack[i]==needle[0]) {
                nextI = i;
                isMark = !isMark;
            }
            ++j;
        }
        else {
            j = 0;
            if(isMark) {
                i = nextI;
                isMark = 0;
            }
            prevI = i;
        }
        if(len1 - prevI < len2) {
            break;
        }
    }

    return -1;
}

int main(int argc, char **argv) {
    char *haystack = "aabaaabaaac";
    char *needle = "aabaaac";

    printf("%d\n", strStr(haystack, needle));

    return 0;
}
