// LeetCode Problem:
// Title: Median of Two Sorted Arrays
// URL: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int isOdd = (nums1Size+nums2Size) % 2;
    int totalSize = nums1Size + nums2Size;
    // previous number and current number
    int cn = -1000000;
    int pn = -1000000;
    int isEnd1 = 0;
    int isEnd2 = 0;

    int i1 = 0;
    int i2 = 0;

    // special case
    if(totalSize <= 1) {
        if(nums1Size != 0) {
            return nums1[0];
        }
        else {
            return nums2[0];
        }
    }
    
    while(i1 + i2 <= totalSize / 2) {
        // check index and size
        if(i1 == nums1Size && isEnd1 == 0) {
            isEnd1 = 1;
        }
        if(i2 == nums2Size && isEnd2 == 0) {
            isEnd2 = 1;
        }

        // read a number orderly
        if(isEnd1 == 0 && isEnd2 == 0) {
            pn = cn;
            if(nums1[i1] < nums2[i2]) {
                cn = nums1[i1];
                ++i1;
            }
            else {
                cn = nums2[i2];
                ++i2;
            }
        }

        // if nums1 is end, then return directly
        else if(isEnd1 == 1) {
            if(isOdd) {
                return nums2[totalSize / 2 - nums1Size];
            }
            pn = cn;
            cn = nums2[i2];
            ++i2;
        }
        // if nums2 is end
        else if(isEnd2 == 1) {
            if(isOdd) {
                return nums1[totalSize / 2 - nums2Size];
            }
            pn = cn;
            cn = nums1[i1];
            ++i1;
        }
    }
    
    // if is odd
    if(isOdd) {
        return (double) cn;
    }
    else {
        return (double) (cn+pn) / 2.0;
    }
}

int main(int argc, char **argv) {
    int nums1[] = {3, 4};
    int nums2[] = {};

    printf("%f\n", findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int)));

    return 0;
}
