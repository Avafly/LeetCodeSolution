#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char * s){
    if(strlen(s) % 2 == 1) {
        return false;
    }
    char recent[10000];
    int count = 0;

    for(int i = 0; i < strlen(s); ++i) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            recent[count++] = s[i];
        }
        else if(s[i] == ')') {
            int idx = --count;
            if(idx < 0) {
                return false;
            }
            if(recent[idx] != '(') {
                return false;
            }
        }
        else if(s[i] == ']') {
            int idx = --count;
            if(idx < 0) {
                return false;
            }
            if(recent[idx] != '[') {
                return false;
            }
        }
        else if(s[i] == '}') {
            int idx = --count;
            if(idx < 0) {
                return false;
            }
            if(recent[idx] != '{') {
                return false;
            }
        }
    }

    return count == 0;
}

int main() {
    char *s = "){";
    
    if(isValid(s) == 0) printf("false\n");
    else printf("true\n");

    return 0;
}
