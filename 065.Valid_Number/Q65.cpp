#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

/*
 * Idea:
 * Check the conditions specified in the problem statement step by step and
 * determines if the given string represents a valid number.
 */

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.size();
        
        // skip leading whitespaces
        while(i < n && isspace(s[i])) {
            ++i;
        }
        
        // check for optional sign
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            ++i;
        }
        
        bool isNumeric = false;
        while(i < n && isdigit(s[i])) {
            ++i;
            isNumeric = true;
        }
        
        if(i < n && s[i] == '.') {
            ++i;
            while(i < n && isdigit(s[i])) {
                ++i;
                isNumeric = true;
            }
        }
        
        if(isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
            ++i;
            isNumeric = false;
            if(i < n && (s[i] == '+' || s[i] == '-')) {
                ++i;
            }
            while(i < n && isdigit(s[i])) {
                ++i;
                isNumeric = true;
            }
        }
        
        // skip trailing whitespaces
        while(i < n && isspace(s[i])) {
            ++i;
        }
        
        return isNumeric && i == n;
    }
};

int main(int argc, char **argv) {

    vector<string> testSet1 = {"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    vector<string> testSet2 = {"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};

    Solution sol = Solution();

    for(auto &s : testSet1) {
        cout << sol.isNumber(s) << " ";
    }
    cout << endl;
    for(auto &s : testSet2) {
        cout << sol.isNumber(s) << " ";
    }
    cout << endl;
    return 0;
}