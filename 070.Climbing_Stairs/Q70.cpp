
// LeetCode Problem:
// Title: Climbing Stairs
// URL: https://leetcode.com/problems/climbing-stairs/

#include <iostream>
using namespace std;

/*
 * Idea: suppose n(k) is the number of distinct ways that can climb to k-th step,
 * thus n(k) = n(k - 1) + n(k - 2)
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n < 1)       return 0;
        else if(n <= 3) return n;

        int prev = 2;
        int curr = 3;
        int temp;
        for(int i = 4; i <= n; ++i) {
            temp = curr;
            curr += prev;
            prev = temp;
        }

        return curr;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    for(int i = 1; i <= 15; ++i) {
        cout << sol.climbStairs(i) << endl;
    }
    return 0;
}