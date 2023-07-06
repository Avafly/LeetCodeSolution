#include <stdio.h>

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

int largestRectangleArea(int* heights, int heightsSize){
    int ans = 0;
    int monoStack[10001] = {0};
    int stackSize = 0;
    
    // iterate through the heights vector
    for(int i = 0; i < heightsSize; ++i) {
        // ensure the stack is non-decreasing
        while(stackSize && heights[i] <= heights[monoStack[stackSize - 1]]) {
            int topIndex = monoStack[stackSize - 1];
            --stackSize;
            int width = !stackSize ? i : i - monoStack[stackSize - 1] - 1;
            ans = MAX(ans, heights[topIndex] * width);
        }
        monoStack[stackSize++] = i;
    }
    
    // process the remaining elements in the stack
    while(stackSize) {
        int topIdex = monoStack[stackSize - 1];
        --stackSize;
        int width = !stackSize ? heightsSize : heightsSize - monoStack[stackSize - 1] - 1;
        ans = MAX(ans, heights[topIdex] * width);
    }

    return ans;
}

int main(int argc, char **argv) {
    int heights[] = {2,1,5,6,2,3};

    printf("%d\n", largestRectangleArea(heights, sizeof(heights) / sizeof(int)));
    
    return 0;
}