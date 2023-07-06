#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 Idea: dynamic programming
 dp[i][j] indicates whether the first i chars of s1 and the first j chars of
 s2 can form the first i+j chars.
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1Size = static_cast<int>(s1.size());
        int s2Size = static_cast<int>(s2.size());
        int s3Size = static_cast<int>(s3.size());

        if(s1Size + s2Size != s3Size) {
            return false;
        }

        vector<vector<bool>> dp(s1Size + 1, vector<bool>(s2Size + 1, false));
        dp[0][0] = true;

        for(int i = 0; i <= s1Size; ++i) {
            for(int j = 0; j <= s2Size; ++j) {
                if(i > 0) {
                    dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
                if(j > 0) {
                    dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[s1Size][s2Size];
    }
};

int main(int argc, char **argv) {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    
    Solution sol;
    cout << (sol.isInterleave(s1, s2, s3) ? "True" : "False") << endl;
    
    return 0;
}
