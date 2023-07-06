#include <stdio.h>
#include <stdbool.h>

/*

  The idea is to split the pattern p into several substrings divided by the *
character, and then verify if these substrings appear in the input string s.
  For example, p is "abc**d?f*ghi", it can be divided into "abc", "d?f", and
"ghi". We then search for matches of these substrings in s. If all the
substrings match successfully in order, the function returns true; otherwise,
it returns false.

*/


bool isMatch(char * s, char * p){
    for(char *lastMatch = s, *lastStar = NULL; *s;) {
        if(*p == *s || *p == '?') {
            p++;
            s++;
        }
        else if(*p == '*') {
            lastStar = ++p;
            lastMatch = s;
        }
        // the star exist
        else if(lastStar) {
            p = lastStar;
            s = ++lastMatch;
        }
        else {
            return false;
        }
    }

    while(*p == '*') {
        p++;
    }

    return !*p;
}

int main(int argc, char **argv) {

    char *s = "baaa";
    char *p = "*aa";

    printf("%s\n", isMatch(s, p) ? "True" : "False");

    return 0;
}