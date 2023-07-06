#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){
    if(x < 0) {
        return false;
    }

    int num = x;
    long rev = 0;
    while(x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    return num == rev;
}

int main(int argc, char **argv) {

    int x = 101;
    printf("%s\n", isPalindrome(x) ? "True" : "False" );

    return 0;
}
