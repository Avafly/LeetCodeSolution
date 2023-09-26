// LeetCode Problem:
// Title: Longest Substring Without Repeating Characters
// URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <string>

using namespace std;

#define SIZE 128

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) {
            return 0;
        }

        int len = static_cast<int>(s.length());
        int maxLen = 1;
        int charList[SIZE] = {0};

        for(int i = 0; i < len - 1; ++i) {
            // reset array
            fill(charList, charList + SIZE, 0);
            ++charList[static_cast<int>(s[i])];

            for(int j = i + 1; j < len; ++j) {
                int asciiIdx = static_cast<int>(s[j]);
                // a value of 0 means this is first char in substring
                if(charList[asciiIdx] == 0) {
                    ++charList[asciiIdx];
                    maxLen = max(maxLen, j - i + 1);
                }
                else {
                    break;
                }
            }
            
            if(maxLen == len) {
                return maxLen;
            }
        }
        return maxLen;
    }
};

int main(int argc, char **argv) {
    string s = "bbbbb";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
