// LeetCode Problem:
// Title: Reverse Integer
// URL: https://leetcode.com/problems/reverse-integer/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x > -10 && x < 10) {
            return x;
        }

        long rev = 0;
        while(x != 0) {
            rev *= 10;
            rev += x % 10;
            if(rev > 2147483647 || rev < -2147483648) {
                return 0;
            }
            x /= 10;
        }
        return rev;
    }
};

int main(int argc, char **argv) {
    int nums = 1534236469;
    cout << nums << endl;
    Solution sol;
    cout << sol.reverse(nums) << endl;

    return 0;
}
