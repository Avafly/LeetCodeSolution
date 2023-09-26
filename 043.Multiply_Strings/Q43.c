
// LeetCode Problem:
// Title: Multiply Strings
// URL: https://leetcode.com/problems/multiply-strings/description/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * multiply(char * num1, char * num2){
    int ans[400] = {0};

    // multiply
    for(int i = strlen(num1) - 1; i >= 0; --i) {
        for(int j = strlen(num2) - 1; j >= 0; --j) {
            int prod = (num1[i] - '0') * (num2[j] - '0');
            int temp = ans[i + j + 1] + prod;
            ans[i + j + 1] = temp % 10;
            ans[i + j] += temp / 10;
        }
    }
    
    // convert array to str

    int i = 0;
    while(i < strlen(num1) + strlen(num2) && ans[i] == 0) {
        ++i;
    }
    
    if(i == strlen(num1) + strlen(num2)) {
        return "0";
    }

    char *ansStr = (char *)malloc(sizeof(char) * (strlen(num1) + strlen(num2) - i + 1));
    memset(ansStr, '\0', strlen(num1) + strlen(num2) - i + 1);
    int i4a = 0;
    for(int j = i; j < strlen(num1) + strlen(num2); ++j) {
        ansStr[i4a++] = ans[j] + '0';
    }

    // return ansStr;
    return ansStr;
}

int main(int argc, char **argv) {
    char *num1 = "9";
    char *num2 = "9";

    char *ans = multiply(num1, num2);
    printf("%s\n", ans);
    if(ans[0] != '0' && ans != NULL) {
        free(ans);
    }

    return 0;
}