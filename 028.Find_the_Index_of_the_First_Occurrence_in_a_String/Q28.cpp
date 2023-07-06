#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();

        int prevI = 0;
        int nextI = 0;
        int isMark = 0;
        int j = 0;
        for(int i=0; i<len1; ++i) {
            if(haystack[i] == needle[j]) {
                if(j == len2-1) {
                    return i - j;
                }
                if(!isMark && haystack[i]==needle[0]) {
                    nextI = i;
                    isMark = !isMark;
                }
                ++j;
            }
            else {
                j = 0;
                if(isMark) {
                    i = nextI;
                    isMark = 0;
                }
                prevI = i;
            }
            if(len1 - prevI < len2) {
                break;
            }
        }

        return -1;
    }
};

int main(int argc, char **argv) {
    string haystack = "aabaaabaaac";
    string needle = "aabaaac";

    Solution sol = Solution();

    cout << sol.strStr(haystack, needle) << endl;;

    return 0;
}