#include <iostream>
#include <string>

using namespace std;

/*
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
*/

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int len = s.length();
        int i = 0;

        while (i < len) {
            //cout << s.substr(i) << "\t" << num << "\t" << i << endl;
            if (i<len-1 && s[i]=='C' && s[i+1]=='M') {
                num += 900;
                i += 2;
            }
            else if (s[i] == 'M') {
                num += 1000;
                ++i;
            }
            else if (i<len-1 && s[i]=='C' && s[i+1]=='D') {
                num += 400;
                i += 2;
            }
            else if (s[i] == 'D') {
                num += 500;
                ++i;
            }
            else if (i<len-1 && s[i]=='X' && s[i+1]=='C') {
                num += 90;
                i += 2;
            }
            else if (s[i] == 'C') {
                num += 100;
                ++i;
            }
            else if (i<len-1 && s[i]=='X' && s[i+1]=='L') {
                num += 40;
                i += 2;
            }
            else if (s[i] == 'L') {
                num += 50;
                ++i;
            }
            else if (i<len-1 && s[i]=='I' && s[i+1]=='X') {
                num += 9;
                i += 2;
            }
            else if (s[i] == 'X') {
                num += 10;
                ++i;
            }
            else if (i<len-1 && s[i]=='I' && s[i+1]=='V') {
                num += 4;
                i += 2;
            }
            else if (s[i] == 'V') {
                num += 5;
                ++i;
            }
            else if (s[i] == 'I') {
                num += 1;
                ++i;
            }
        }

        return num;
    }
};

int main(int argc, char **argv) {

    Solution sol = Solution();

    cout << sol.romanToInt("MCMXCIV") << endl;

    return 0;
}