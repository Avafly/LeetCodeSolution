
// LeetCode Problem:
// Title: Decode Ways
// URL: https://leetcode.com/problems/decode-ways/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= s.size(); ++i) {
            if(s[i - 1] != '0') dp[i] += dp[i - 1];
            if(10 <= stoi(s.substr(i - 2, 2)) && stoi(s.substr(i - 2, 2)) <= 26) dp[i] += dp[i - 2];
        }

        return dp.back();
    }
};

int main(int argc, char **argv) {
    string s = "12";
    
    Solution sol;
    cout << sol.numDecodings(s) << endl;
    
    return 0;
}
