#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = -1;
        int ans = 0;
        vector<int> stack;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '(') {
                stack.push_back(i);
            }
            else {
                if(stack.size() == 0) {
                    left = i;
                }
                else {
                    stack.pop_back();
                    if(stack.size() == 0) {
                        ans = max(ans, i-left);
                    }
                    else {
                        ans = max(ans, i-stack.back());
                    }
                }
            }
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    string s = "))))((()((";
    cout << s << "\n- - - - - -" << endl;
    cout << sol.longestValidParentheses(s) << endl;

    return 0;
}
