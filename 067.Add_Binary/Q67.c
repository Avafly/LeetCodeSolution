#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

char * addBinary(char * a, char * b){
    int ai = strlen(a) - 1;
    int bi = strlen(b) - 1;
    int carry = 0;
    char *temp = (char *)calloc(MAX(strlen(a), strlen(b)) + 2, sizeof(char));
    int count = MAX(ai, bi) + 1;

    while(ai >= 0 || bi >= 0 || carry) {
        int sum = carry;
        carry = 0;

        if(ai >= 0 && bi >= 0) {
            sum += a[ai] - '0' + b[bi] - '0';
            --ai;
            --bi;
        }
        else if(ai >= 0) {
            sum += a[ai] - '0';
            --ai;
        }
        else if(bi >= 0) {
            sum += b[bi] - '0';
            --bi;
        }
        carry = sum / 2;
        temp[count--] = (sum % 2) + '0';
    }

    /* create answer */
    // if no carry
    if(count == 0) {
        int returnSize = MAX(strlen(a), strlen(b)) + 1;
        char *ans = (char *)calloc(returnSize, sizeof(char));
        for(int i = 0; i < returnSize; ++i) {
            ans[i] = temp[i + 1];
        }
        free(temp);
        return ans;
    }
    // if a carry exists
    else {
        return temp;
    }
}

int main(int argc, char **argv) {

    char *a = "0";
    char *b = "0";

    char *ans = addBinary(a, b);

    printf("%s\n", ans);

    // free the memory
    free(ans);

    return 0;
}