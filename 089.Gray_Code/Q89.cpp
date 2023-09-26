
// LeetCode Problem:
// Title: Gray Code
// URL: https://leetcode.com/problems/gray-code/

#include <iostream>
#include <vector>
using namespace std;

/*
 Gray code = Binary number XOR (Binary number >> 1)
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> ans(size, 0);
        for(int i = 0; i < size; ++i) {
            ans[i] = i ^ (i >> 1);
        }
        return ans;
    }
};

int main(int argc, char **argv) {
    int n = 5;
    
    Solution sol;
    vector<int> ans = sol.grayCode(n);
    for(auto &n : ans) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}
