#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;

/*
 Idea: double pointers
 */

class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = static_cast<int>(s.size()), tSize = static_cast<int>(t.size());
        if(tSize > sSize) return "";
        int count_t[58] = {0};
        int count_s[58] = {0};
        int l = 0, r = 0;
        int minLen = numeric_limits<int>::max();
        int char_n = 0;
        int uniq_char = 0;
        int start = 0;
        
        /* count t's chars */
        for(int i = 0; i < tSize; ++i) {
            if(count_t[t[i] - 'A'] == 0) {
                ++uniq_char;
            }
            ++count_t[t[i] - 'A'];
        }

        /* double pointers */
        while(l < sSize && r < sSize) {
            // right pointer
            for(; r < sSize; ++r) {
                if(t.find(s[r]) != string::npos) {  // if s[r] is in t
                    ++count_s[s[r] - 'A'];
                    if(count_s[s[r] - 'A'] == count_t[s[r] - 'A']) {
                        if(char_n < uniq_char) {
                            ++char_n;
                        }
                    }
                    if(char_n >= uniq_char) {
                        break;
                    }
                }
            }
            // check if all chars in t were appeared in s
            if(char_n < uniq_char) {
                return "";
            }
            // left pointer
            for(; l < sSize; ++l) {
                if(t.find(s[l]) != string::npos) {  // if s[l] is in t
                    // move l to right as far as possible while containing all chars in t
                    if(count_s[s[l] - 'A'] == count_t[s[l] - 'A']) {
                        if(r - l + 1 < minLen) {
                            start = l;
                            minLen = r - l + 1;
                        }
                        break;
                    }
                    else {
                        --count_s[s[l] - 'A'];
                    }
                }
            }
            ++r;
        }
        
        return s.substr(start, minLen);
    }
};

int main(int argc, char **argv) {
    string s = "cabwefgewcwaefgcf";
    string t = "cae";

    Solution sol;
    cout << sol.minWindow(s, t) << endl;

    return 0;
}
