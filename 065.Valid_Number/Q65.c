#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/*
 * Idea:
 * Check the conditions specified in the problem statement step by step and
 * determines if the given string represents a valid number.
 */

bool isNumber(char * s){
    int i = 0;
    int n = strlen(s);
    
    // skip leading whitespaces
    while(i < n && isspace(s[i])) {
        ++i;
    }
    
    // check for optional sign
    if(i < n && (s[i] == '+' || s[i] == '-')) {
        ++i;
    }
    
    bool isNumeric = false;
    while(i < n && isdigit(s[i])) {
        ++i;
        isNumeric = true;
    }
    
    if(i < n && s[i] == '.') {
        ++i;
        while(i < n && isdigit(s[i])) {
            ++i;
            isNumeric = true;
        }
    }
    
    if(isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
        ++i;
        isNumeric = false;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            ++i;
        }
        while(i < n && isdigit(s[i])) {
            ++i;
            isNumeric = true;
        }
    }
    
    // skip trailing whitespaces
    while(i < n && isspace(s[i])) {
        ++i;
    }
    
    return isNumeric && i == n;

    return true;
}

int main(int argc, char **argv) {

    // test input
    char *s[] = {
        "0089",
        "-0.1",
        "1145",
        "1e12",
        "9e2.",
        "--60",
        "abcd",
        "-+34",
    };
    
    for(int i = 0; i < sizeof(s) / sizeof(s[0]); ++i) {
        printf("%s\n", isNumber(s[i]) ? "True" : "False");
    }

    return 0;
}