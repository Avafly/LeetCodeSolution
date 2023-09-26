
// LeetCode Problem:
// Title: Maximal Rectangle
// URL: https://leetcode.com/problems/maximal-rectangle/

#include <stdio.h>
#include <stdlib.h>

/*
 Idea
 For each cell in the matrix, if its value is '1', calculate and store the
 number of consecutive '1's immediately above it, including itself. If its
 value is '0', store '0' for that cell.
 Then, treat the preprocessed values as histogram heights and find the
 largest rectangle in the histogram (as Leetcode problem 84).
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct STACK {
    int data;
    struct STACK *next;
} STACK;

void push(STACK **stack, int data) {
    STACK *newNode = (STACK *)malloc(sizeof(STACK));
    newNode->data = data;
    newNode->next = *stack;
    *stack = newNode;
}

int pop(STACK **stack) {
    if (*stack == NULL) {
        return -1;
    }
    
    int data = (*stack)->data;
    STACK *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return data;
}

int top(STACK *stack) {
    if (stack == NULL) {
        return -1;
    }
    
    return stack->data;
}

int largestRectangleArea(int *heights, int heightsSize){
    int ans = 0;
    STACK *monoStack = NULL;
    
    // iterate through the heights vector
    for(int i = 0; i < heightsSize; ++i) {
        // ensure the stack is non-decreasing
        while(monoStack && heights[i] <= heights[top(monoStack)]) {
            int topIndex = pop(&monoStack);
            int width = !monoStack ? i : i - top(monoStack) - 1;
            ans = MAX(ans, heights[topIndex] * width);
        }
        push(&monoStack, i);
    }
    
    // process the remaining elements in the stack
    while(monoStack) {
        int topIdex = pop(&monoStack);
        int width = !monoStack ? heightsSize : heightsSize - top(monoStack) - 1;
        ans = MAX(ans, heights[topIdex] * width);
    }

    return ans;
}

int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize){
    int *heights = (int *)calloc(*matrixColSize, sizeof(int));
    int ans = 0;
    
    for(int i = 0; i < matrixSize; ++i) {
        for(int j = 0; j < *matrixColSize; ++j) {
            if(matrix[i][j] == '0') {
                heights[j] = 0;
            }
            else {
                heights[j] += 1;
            }
        }
        ans = MAX(ans, largestRectangleArea(heights, *matrixColSize));
    }
    
    free(heights);
    
    return ans;
}

int main(int argc, char **argv) {
    char matrixData[][5] = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    };
    int matrixSize = sizeof(matrixData) / sizeof(matrixData[0]);
    int matrixColSize = sizeof(matrixData[0]) / sizeof(char);
    char **matrix = (char **)malloc(sizeof(char *) * matrixSize);
    for(int i = 0; i < matrixSize; ++i) {
        matrix[i] = (char *)malloc(sizeof(char) * matrixColSize);
        for(int j = 0; j < matrixColSize; ++j) {
            matrix[i][j] = matrixData[i][j];
        }
    }
    
    printf("%d\n", maximalRectangle(matrix, matrixSize, &matrixColSize));
    
    /* free the memory */
    for(int i = 0; i < matrixSize; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
