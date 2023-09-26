
// LeetCode Problem:
// Title: Merge Intervals
// URL: https://leetcode.com/problems/merge-intervals/

#include <stdio.h>
#include <stdlib.h>

#define ARRSIZE 8

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int compare(const void *a, const void *b) {
    int *arr1 = *(int**)a;
    int *arr2 = *(int**)b;
    if(arr1[0] == arr2[0]) {
        return arr1[1] - arr2[1];
    }
    else {
        return arr1[0] - arr2[0];   
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int[2]), compare);

    /* print sorted array */
    // for(int i = 0; i < intervalsSize; ++i) {
    //     printf("%d %d\n", intervals[i][0], intervals[i][1]);
    // }

    int temp[10000][2] = {0};
    int count = 0;

    int start = intervals[0][0];
    int end = intervals[0][1];

    for(int i = 1; i < intervalsSize; ++i) {
        // non-overlapping intervals, add to the result
        if(intervals[i][0] > end) {
            temp[count][0] = start;
            temp[count++][1] = end;
            start = intervals[i][0];
            end = intervals[i][1];
        }
        // overlapping intervals, merge them
        else {
            end = MAX(end, intervals[i][1]);
        }
    }

    *returnSize = count + 1;

    /* create answer */
    int **ans = (int **)malloc(sizeof(int *) * (*returnSize));
    for(int i = 0; i < count; ++i) {
        ans[i] = (int *)malloc(sizeof(int) * 2);
        ans[i][0] = temp[i][0];
        ans[i][1] = temp[i][1];
    }
    ans[*returnSize - 1] = (int *)malloc(sizeof(int) * 2);
    ans[*returnSize - 1][0] = start;
    ans[*returnSize - 1][1] = end;

    /* create returnColumnSizes */
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = 2;
    }
    return ans;
}

int main(int argc, char **argv) {
    int **intervals = (int **)malloc(sizeof(int *) * ARRSIZE);
    for(int i = 0; i < ARRSIZE; ++i) {
        intervals[i] = (int *)malloc(sizeof(int) * 2);
    }
    intervals[0][0] = 2;
    intervals[0][1] = 3;
    intervals[1][0] = 1;
    intervals[1][1] = 3;
    intervals[2][0] = 2;
    intervals[2][1] = 2;
    intervals[3][0] = 2;
    intervals[3][1] = 2;
    intervals[4][0] = 0;
    intervals[4][1] = 0;
    intervals[5][0] = 3;
    intervals[5][1] = 3;
    intervals[6][0] = 4;
    intervals[6][1] = 5;
    intervals[7][0] = 6;
    intervals[7][1] = 7;

    int intervalsColSize[] = {2, 2, 2, 2, 2, 2, 2, 2};
    int *returnSize = (int *)malloc(sizeof(int));
    int *returnColumnSizes = NULL;

    int **ans = merge(intervals, ARRSIZE, intervalsColSize, returnSize, &returnColumnSizes);

    for(int i = 0; i < *returnSize; ++i) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }

    /* free the memory */
    for(int i = 0; i < ARRSIZE; ++i) {
        free(intervals[i]);
    }
    free(intervals);
    for(int i = 0; i < *returnSize; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
    free(returnSize);
    return 0;
}