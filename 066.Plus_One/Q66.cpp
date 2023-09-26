
// LeetCode Problem:
// Title: Plus One
// URL: https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        digits.back() += 1;

        for(int i = digits.size() - 1; i > 0; --i) {
            if(digits[i] > 9) {
                digits[i - 1] += 1;
                digits[i] -= 10;
            }
            else {
                break;
            }
        }

        // handle the first digit
        if(digits[0] > 9) {
            digits[0] -= 10;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();
    vector<int> digits = {9, 8, 9, 0, 8};
    vector<int> ans = sol.plusOne(digits);
    for(auto &n : ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}