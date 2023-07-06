#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans, char_table;
        if(digits.empty()) {
            return ans;
        }

        char_table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        rec(ans, char_table, digits, "");
        
        return ans;
    }

    void rec(vector<string> &ans, vector<string> &char_table, string digits, string comb) {
        if(digits.empty()) {
            ans.push_back(comb);
            return;
        }

        string d2c(char_table[(digits[0] - '0')]);
        for(int i = 0; i < d2c.length(); ++i) {
            string s(1, d2c[i]);
            rec(ans, char_table, digits.substr(1), comb + s);
        }
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();
    string digits = "333";
    vector<string> ans = sol.letterCombinations(digits);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    cout << ans.size() << endl;

    return 0;
}
