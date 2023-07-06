#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = static_cast<int>(nums1.size()) + static_cast<int>(nums2.size());
        if(total % 2 == 1) {
            return findKthElement(nums1, nums2, total / 2 + 1);
        }
        else {
            return (findKthElement(nums1, nums2, total / 2) + findKthElement(nums1, nums2, total / 2 + 1)) / 2.0;
        }
    }

private:
    int findKthElement(const vector<int> &nums1, const vector<int> &nums2, int k) {
        int m = static_cast<int>(nums1.size());
        int n = static_cast<int>(nums2.size());
        int index1 = 0, index2 = 0;
        
        while(true) {
            if(index1 == m) {
                return nums2[index2 + k - 1];
            }
            if(index2 == n) {
                return nums1[index1 + k - 1];
            }
            if(k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if(pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
};

int main(int argc, char **argv) {

    int arr1[] = {2, 3};
    int arr2[] = {};

    vector<int> nums1(arr1, arr1+(sizeof(arr1)/sizeof(int)));
    vector<int> nums2(arr2, arr2+(sizeof(arr2)/sizeof(int)));

    Solution sol;

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
