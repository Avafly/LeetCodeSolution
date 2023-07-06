#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
*/

int romanToInt(char *s) {
    int num = 0;

    while (strlen(s) != 0) {
        //printf("%s\t%d\n", s, num);

        if (strlen(s)>1 && s[0]=='C' && s[1]=='M') {
            num += 900;
            s += 2;
        }
        else if (s[0] == 'M') {
            num += 1000;
            ++s;
        }
        else if (strlen(s)>1 && s[0]=='C' && s[1]=='D') {
            num += 400;
            s += 2;
        }
        else if (s[0] == 'D') {
            num += 500;
            ++s;
        }
        else if (strlen(s)>1 && s[0]=='X' && s[1]=='C') {
            num += 90;
            s += 2;
        }
        else if (s[0] == 'C') {
            num += 100;
            ++s;
        }
        else if (strlen(s)>1 && s[0]=='X' && s[1]=='L') {
            num += 40;
            s += 2;
        }
        else if (s[0] == 'L') {
            num += 50;
            ++s;
        }
        else if (strlen(s)>1 && s[0]=='I' && s[1]=='X') {
            num += 9;
            s += 2;
        }
        else if (s[0] == 'X') {
            num += 10;
            ++s;
        }
        else if (strlen(s)>1 && s[0]=='I' && s[1]=='V') {
            num += 4;
            s += 2;
        }
        else if (s[0] == 'V') {
            num += 5;
            ++s;
        }
        else if (s[0] == 'I') {
            num += 1;
            ++s;
        }
    }

    return num;
}

int main(int argc, char **argv) {

    printf("%d\n", romanToInt("IX"));


    return 0;
}