#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while(i < n) {
            int j = i, len = 0;
            // i indicates the starting word, and j indicates ending word of each line
            while(j < n && len + words[j].length() + j - i <= maxWidth) {
                len += words[j].length();
                ++j;
            }
            
            int spaces = maxWidth - len;
            int numWords = j - i;

            /* add the first word of this line */
            ans.push_back(words[i]);
            /* add subsequent words of this line */
            // when line should be left-justified
            if(j == n || numWords == 1) {
                for(int k = i + 1; k < j; ++k) {
                    ans.back() += " " + words[k];
                }
                ans.back() += string(maxWidth - ans.back().length(), ' ');
            }
            // or the words should be distributed as evenly as possible
            else {
                int avgSpaces = spaces / (numWords - 1);
                int extraSpaces = spaces % (numWords - 1);

                for(int k = i + 1; k < j; ++k) {
                    ans.back() += string(avgSpaces + (k - i <= extraSpaces ? 1 : 0), ' ') + words[k];
                }
            }
            i = j;
        }
        return ans;
    }
};


int main(int argc, char **argv) {
    vector<string> words = {"Science","is","what","we","understand",
                            "well","enough","to","explain","to","a",
                            "computer.","Art","is","everything","else",
                            "we","do"};
    int maxWidth = 20;

    Solution sol = Solution();
    vector<string> ans = sol.fullJustify(words, maxWidth);
    for(auto &line : ans) {
         cout << "\"" << line << "\"" << endl;
    }

    return 0;
}