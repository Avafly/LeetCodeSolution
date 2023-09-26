
// LeetCode Problem:
// Title: Valid Parentheses
// URL: https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1) {
            return false;
        }
        char recent[10000];
        int count = 0;

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                recent[count++] = s[i];
            }
            else if(s[i] == ')') {
                int idx = --count;
                if(idx < 0) {
                    return false;
                }
                if(recent[idx] != '(') {
                    return false;
                }
            }
            else if(s[i] == ']') {
                int idx = --count;
                if(idx < 0) {
                    return false;
                }
                if(recent[idx] != '[') {
                    return false;
                }
            }
            else if(s[i] == '}') {
                int idx = --count;
                if(idx < 0) {
                    return false;
                }
                if(recent[idx] != '{') {
                    return false;
                }
            }
        }

        return count == 0;
    }
};

int main(int argc, char **argv) {

    Solution sol = Solution();

    string s("({})");
    cout << (sol.isValid(s) ? "True" : "False") << endl;
    return 0;
}
