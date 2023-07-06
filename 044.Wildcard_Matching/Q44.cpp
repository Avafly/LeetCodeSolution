#include <iostream>
#include <string>
using namespace std;

/*

  The idea is to split the pattern p into several substrings divided by the *
character, and then verify if these substrings appear in the input string s.
  For example, p is "abc**d?f*ghi", it can be divided into "abc", "d?f", and
"ghi". We then search for matches of these substrings in s. If all the
substrings match successfully in order, the function returns true; otherwise,
it returns false.

*/

class Solution {
public:
    bool isMatch(string s, string p) {
        bool isStar = false;
        for(string lastMatch = s, lastStar; !s.empty();) {
            if(p[0] == s[0] || p[0] == '?') {
                p = p.substr(1);
                s = s.substr(1);
            }
            else if(p[0] == '*') {
                isStar = true;
                p = p.substr(1);
                lastStar = p;
                lastMatch = s;
            }
            else if(isStar) {
                p = lastStar;
                lastMatch = lastMatch.substr(1);
                s = lastMatch;
            }
            else {
                return false;
            }
        }

        while(p[0] == '*') {
            p = p.substr(1);
        }

        return p.empty();
    }
};

int main(int argc, char **argv) {

    Solution sol = Solution();

    string s = "aa";
    string p = "*";

    cout << (sol.isMatch(s, p) ? "True" : "False") << endl;

    return 0;
}