
// LeetCode Problem:
// Title: Merge Sorted Array
// URL: https://leetcode.com/problems/merge-sorted-array/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n){
    for(int i = m, j = 0; j < n; ++i){
        nums1[i] = nums2[j];
        ++j;
    }
    qsort(nums1, nums1Size, sizeof(int), cmp);
}

int main(int argc, char **argv) {
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    int m = 3;
    int n = 3;
    
    merge(nums1, sizeof(nums1) / sizeof(int), m, nums2, sizeof(nums2) / sizeof(int), n);
    
    for(int i = 0; i < sizeof(nums1) / sizeof(int); ++i) {
        printf("%d ", nums1[i]);
    }
    printf("\n");
    
    return 0;
}
