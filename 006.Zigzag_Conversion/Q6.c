// LeetCode Problem:
// Title: Zigzag Conversion
// URL: https://leetcode.com/problems/zigzag-conversion/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = (int) strlen(s);

    // check special cases
    if(numRows <= 1 || len == numRows) {
        return s;
    }

    // initialization
    char *zigzag = (char *)calloc(len + 1, sizeof(char));
    int c = 0;
    int j = 0;

    for(int i = 0; i < numRows; ++i) {
        j = i;
        // looking for next char using delta1 and delta2 alternately
        int delta1 = i * 2;
        int delta2 = (numRows - i - 1) * 2;
        int flag = 0;
        int delta = 0;

        while(j < len) {
            zigzag[c++] = s[j];
            delta = 0;

            while(delta == 0) {
                if(flag)
                    delta = delta1;
                else
                    delta = delta2;
                flag = !flag;
            }
            j += delta;
        }
    }

    return zigzag;
}

int main(int argc, char **argv) {
    char *s = "PAYPALISHIRING";
    int numRows = 3;

    char *zigzag = convert(s, numRows);
    printf("%s\n", zigzag);
    free(zigzag);

    return 0;
}
