
// LeetCode Problem:
// Title: Generate Parentheses
// URL: https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec(ans, 0, 0, n, "");

        return ans;
    }

private:
    void rec(vector<string> &ans, int left, int right, int n, string per) {
        if(left == n && right == n) {
            ans.push_back(per);
            return;
        }
        if(left < n) {
            rec(ans, left + 1, right, n, per + "(");
        }
        if(right < n && left > right) {
            rec(ans, left, right + 1, n, per + ")");
        }
    }
};

int main(int argc, char **argv) {

    Solution sol = Solution();

    int n = 3;
    vector<string> ans = sol.generateParenthesis(n);
    for(int i=0; i<ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}