
// LeetCode Problem:
// Title: Largest Rectangle in Histogram
// URL: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <stdio.h>
#include <stdlib.h>

/*
 Idea: monotonic stack
 The non-decreasing monotonic stack records the index of heights. The previous
 index of the i-th index (i.e., index_{i}), index_{i-1}, represents the index
 where the height is smaller than height[index_{i}]. Therefore, the lowest
 height between index_{i-1} + 1 and index_{i} is height[index_{i}]. Then, the
 width can be computed by index_{i} - index_{i-1} - 1, and the area can be
 calculated by width * height.
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

int main(int argc, char **argv) {
    int heights[] = {2,1,5,6,2,3};

    printf("%d\n", largestRectangleArea(heights, sizeof(heights) / sizeof(int)));
    
    return 0;
}