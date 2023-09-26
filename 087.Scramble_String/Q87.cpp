
// LeetCode Problem:
// Title: Scramble String
// URL: https://leetcode.com/problems/scramble-string/

#include <iostream>
#include <string>
using namespace std;

/*
 Idea
 state transformation equation:
 f(s1, s2) = ⋁_{i=1}^{n-1} (f(s1(0,i), s2(0,i)) ∧ f(s1(i,n-i), s2(i,n-i))) ∨
                           (f(s1(0,i), s2(n-1,i)) ∧ f(s1(i,n-i), s2(0,n-i)))
 */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = static_cast<int>(s1.size());
        bool map[n + 1][n][n];
        memset(map, false, sizeof(map));
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= n - i; ++j) {
                for(int k = 0; k <= n - i; ++k) {
                    if(i == 1) {
                        map[1][j][k] = s1[j] == s2[k];
                    }
                    else {
                        for(int p = 1; p < i; p++) {
                            if((map[p][j][k] && map[i - p][j + p][k + p]) || (map[p][j + i - p][k] && map[i - p][j][k + p])) {
                                map[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        return map[n][0][0];
    }
};

int main(int argc, char **argv) {
    string s1 = "eebaacbcbcadaaedceaaacadccd";
    string s2 = "eadcaacabaddaceacbceaabeccd";
    
    Solution sol;
    cout << (sol.isScramble(s1, s2) ? "True" : "False") << endl;
    
    return 0;
}
