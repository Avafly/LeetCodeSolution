#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    ++digits[digitsSize - 1];

    for(int i = digitsSize - 1; i > 0; --i) {
        if(digits[i] > 9) {
            ++digits[i - 1];
            digits[i] -= 10;
        }
        else {
            break;
        }
    }

    // handle the first digit
    if(digits[0] > 9) {
        *returnSize = digitsSize + 1;
        digits[0] -= 10;
    }
    else {
        *returnSize = digitsSize;
    }

    /* create answer */
    int *ans = (int *)calloc(*returnSize, sizeof(int));
    // if first digit is greater than 9
    if(*returnSize == digitsSize) {
        for(int i = 0; i < digitsSize; ++i) {
            ans[i] = digits[i];
        }
    }
    // if first digit isn't greater than 9
    else {
        ans[0] = 1;
        for(int i = 0; i < digitsSize; ++i) {
            ans[i + 1] = digits[i];
        }
    }

    return ans;
}

int main(int argc, char **argv) {
    int digits[] = {1, 2, 3};
    int digitsSize = sizeof(digits) / sizeof(int);
    int *returnSize = (int *)calloc(1, sizeof(int));

    int *ans = plusOne(digits, digitsSize, returnSize);

    for(int i = 0; i < *returnSize; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    // free the memory
    free(ans);
    free(returnSize);
    return 0;
}