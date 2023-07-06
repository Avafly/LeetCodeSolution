#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRSIZE 1
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    if(intervalsSize == 0) {
        int **ans = (int **)malloc(sizeof(int *) * (*returnSize));
        ans[0] = (int *)malloc(sizeof(int) * 2);
        ans[0][0] = newInterval[0];
        ans[0][1] = newInterval[1];
        *returnSize = 1;
        return ans;
    }

    int intervalsArr[10001][2] = {0};
    int countArr = 0;

    bool flag = true;

    // insert newInterval in the appropriate position
    for(int i = 0; i < intervalsSize; ++i) {
        if(flag && intervals[i][0] > newInterval[0]) {
            intervalsArr[countArr][0] = newInterval[0];
            intervalsArr[countArr++][1] = newInterval[1];
            flag = false;
        }
        intervalsArr[countArr][0] = intervals[i][0];
        intervalsArr[countArr++][1] = intervals[i][1];
    }
    // newInterval not added, newInterval is larger than all the elements in intervals, so add newInterval at the end
    if(flag) {
        intervalsArr[countArr][0] = newInterval[0];
        intervalsArr[countArr++][1] = newInterval[1];
    }

    /* print intervalsArr */
    // for(int i = 0; i < countArr; ++i) {
    //     printf("%d %d\n", intervalsArr[i][0], intervalsArr[i][1]);
    // }

    int temp[10001][2] = {0};
    int countAns = 0;

    temp[countAns][0] = intervalsArr[0][0];
    temp[countAns++][1] = intervalsArr[0][1];

    for(int i = 1; i < countArr; ++i) {
        if(temp[countAns - 1][1] >= intervalsArr[i][0]) {
            temp[countAns - 1][1] = MAX(temp[countAns - 1][1], intervalsArr[i][1]);
        }
        else {
            temp[countAns][0] = intervalsArr[i][0];
            temp[countAns++][1] = intervalsArr[i][1];
        }
    }

    /* print answer */
    // for(int i = 0; i < countAns; ++i) {
    //     printf("%d %d\n", temp[i][0], temp[i][1]);
    // }

    *returnSize = countAns;

    /* create answer */
    int **ans = (int **)malloc(sizeof(int *) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i) {
        ans[i] = (int *)malloc(sizeof(int) * 2);
        ans[i][0] = temp[i][0];
        ans[i][1] = temp[i][1];
    }

    /* create returnColumnSizes */
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = 2;
    }

    return ans;
}

int main(int argc, char **argv) {
    // int intervals[][2] = {
    //     {1, 5},
    //     {3, 3},
    //     {3, 3},
    //     {3, 3},
    //     {3, 3},
    // };
    int intervals[1][2] = {{1, 5}};

    //int *p[ARRSIZE] = {intervals[0], intervals[1], intervals[2], intervals[3], intervals[4]};
    int *p[ARRSIZE] = {intervals[0]};

    int newInterval[] = {6, 6};
    //int intervalsColSize[] = {2, 2, 2, 2, 2};
    int intervalsColSize[] = {2};
    int *returnSize = (int *)malloc(sizeof(int));
    int *returnColumnSizes = NULL;

    int **ans = insert(p, sizeof(intervals) / sizeof(int *),
                       intervalsColSize, newInterval,
                       sizeof(newInterval) / sizeof(int),
                       returnSize, &returnColumnSizes);

    for(int i = 0; i < *returnSize; ++i) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }

    /* free the memory */
    for(int i = 0; i < *returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
    free(returnSize);

    return 0;
}