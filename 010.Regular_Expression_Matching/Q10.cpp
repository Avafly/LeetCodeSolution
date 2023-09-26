// LeetCode Problem:
// Title: Regular Expression Matching
// URL: https://leetcode.com/problems/regular-expression-matching/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == "") {
            return s == "";
        }

        // check whether first char is match, as the prior condition of '*' loop
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        
        // is the case of no '*' loop
        if(p.size() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        }
        else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main(int argc, char **argv) {
    string s = "aaaaaaaaaaaaaaaaaaa";
    string p = "a*a*a*a*a*a*a*a*a*b";
    Solution sol;
    cout << (sol.isMatch(s, p) ? "True" : "False") << endl;

    return 0;
}
