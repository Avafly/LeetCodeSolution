
// LeetCode Problem:
// Title: Permutation Sequence
// URL: https://leetcode.com/problems/permutation-sequence/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * The key idea of this problem is: treat the entries with the same first character
 * as a zone. Identify zone where k resides when permutation size is n, and append
 * first character of that zone to the answer. Then, update k and n. Next, find
 * the interval where k resides when the size is n-1, and continue this process
 * until n=1.
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        int factValue[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        k -= 1;

        int count = 0;
        string ans(n, '0');
        string arr(n, '0');
        for(int i = 0; i < n; ++i) {
            arr[i] = '1' + i;
        }

        while(n > 1) {
            // find zone where k located
            int zone = int(k / factValue[n - 1]);
            // add this char to answer and delete this char
            ans[count++] = arr[zone];
            // delete the previous zones
            arr.erase(arr.begin() + zone);
            // update k and n
            k -= factValue[n - 1] * zone;
            --n;
        }
        ans[count] = arr[0];

        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    int n = 4;
    int k = 15;

    cout << sol.getPermutation(n, k) << endl;

    return 0;
}


