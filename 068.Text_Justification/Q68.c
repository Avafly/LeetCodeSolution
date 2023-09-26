
// LeetCode Problem:
// Title: Text Justification
// URL: https://leetcode.com/problems/text-justification/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fullJustify(char **words, int wordsSize, int maxWidth, int *returnSize){
    char **ans = (char **)malloc(sizeof(char *) * wordsSize);
    *returnSize = 0;
    int i = 0;
    int count = 0;

    while(i < wordsSize) {
        int j = i, len = 0;
        // i indicates the starting word, and j indicates ending word of each line
        while(j < wordsSize && len + strlen(words[j]) + j - i <= maxWidth) {
            len += strlen(words[j]);
            ++j;
        }

        int spaces = maxWidth - len;
        int numWords = j - i;

        ans[count] = (char *)calloc(maxWidth + 1, sizeof(char));
        /* add the first word of this line */
        // k indicates the index for inserting char
        int k = 0;
        for(; k < strlen(words[i]); ++k) {
            ans[count][k] = words[i][k];
        }
        /* add subsequent words of this line */
        // when line should be left-justified
        if(j == wordsSize || numWords == 1) {
            for(int q = i + 1; q < j; ++q) {
                ans[count][k++] = ' ';
                for(int p = 0; p < strlen(words[q]); ++p) {
                    ans[count][k++] = words[q][p];
                }
            }
            while(k < maxWidth) {
                ans[count][k++] = ' ';
            }
        }
        // or the words should be distributed as evenly as possible
        else {
            int avgSpaces = spaces / (numWords - 1);
            int extraSpaces = spaces % (numWords - 1);

            for(int q = i + 1; q < j; ++q) {
                // insert spaces
                for(int p = 0; p < avgSpaces + (q - i <= extraSpaces ? 1 : 0); ++p) {
                    ans[count][k++] = ' ';
                }
                // insert q-th word
                for(int p = 0; p < strlen(words[q]); ++p) {
                    ans[count][k++] = words[q][p];
                }
            }
        }
        i = j;
        ++count;
        ++(*returnSize);
    }

    return ans;
}

int main() {
    // create words
    char *words[] = {
        "This",
        "is",
        "an",
        "example",
        "of",
        "text",
        "justification."
    };
    int wordsSize = sizeof(words) / sizeof(char *);

    int maxWidth = 16;
    int *returnSize = (int *)malloc(sizeof(int));

    char **ans = fullJustify(words, wordsSize, maxWidth, returnSize);

    for(int i = 0; i < *returnSize; ++i) {
        printf("\"%s\"\n", ans[i]);
    }

    // free the memory
    for(int i = 0; i < *returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnSize);
    return 0;
}