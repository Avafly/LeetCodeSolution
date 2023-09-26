
// LeetCode Problem:
// Title: Multiply Strings
// URL: https://leetcode.com/problems/multiply-strings/description/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size() + num2.size(), 0);
        string ansStr = "";

        // multiply
        for(int i = num1.size() - 1; i >= 0; --i) {
            for(int j = num2.size() - 1; j >= 0; --j) {
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int temp = ans[i + j + 1] + prod;
                ans[i + j + 1] = temp % 10;
                ans[i + j] += temp / 10;
            }
        }

        // skip leading zeros
        int i = 0;
        while(i < ans.size() && ans[i] == 0)  ++i;
        // convert vector to string
        for(; i < ans.size(); ++i) {
            ansStr += ans[i] + '0';
        }

        return ansStr.empty() ? "0" : ansStr;
    }
};

int main(int argc, char **argv) {

    Solution sol = Solution();

    string num1 = "0";
    string num2 = "0";

    cout << sol.multiply(num1, num2) << endl;

    return 0;
}