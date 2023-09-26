
// LeetCode Problem:
// Title: Longest Common Prefix
// URL: https://leetcode.com/problems/longest-common-prefix/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strsSize = static_cast<int>(strs.size());
        if(strsSize == 0) {
            return "";
        }
        if(strsSize == 1) {
            return strs[0];
        }

        int count = 0;
        int i;
        string prefix = "";

        for(int j = 0; j < strs[0].length(); ++j) {
            for(i = 1; i < strsSize; ++i) {
                if(strs[0][count] != strs[i][count]) {
                    break;
                }
            }
            if(i == strsSize) {
                prefix += strs[0][count++];
            }
            else {
                break;
            }
        }

        return prefix;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    vector<string> strs;
    strs.push_back("abc");
    strs.push_back("abc");

    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
}
