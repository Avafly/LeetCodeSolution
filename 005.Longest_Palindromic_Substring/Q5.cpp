#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()){
            return "";
        }
        if(s.size() == 1) {
            return s;
        }
        
        int min_start = 0;
        int max_len = 1;
        int i = 0;
        while(i < s.size()) {
            if(s.size() - i <= max_len / 2) {
                break;
            }
            int j = i;
            int k = i;
            while(k < s.size() - 1 && s[k + 1] == s[k]) {
                ++k;
            }
            i = k + 1;
            while(k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {
                ++k;
                --j;
            }
            int new_len = k - j + 1;
            if(new_len > max_len) {
                min_start = j;
                max_len = new_len;
            }
        }
        return s.substr(min_start, max_len);
    }
};

int main(int argc, char **argv) {
    string s = "jkqlwjkjdas";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;

    return 0;
}
