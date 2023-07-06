#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len = static_cast<int>(s.length());
        bool flag = true;
        bool zeroflag = true;
        long num = 0;
        int start = 0;
        int end = 0;
        int bound = 0;

        for (int i = 0; i < len; ++i) {
            /*
            flag == true: no number has been encountered yet
            flag == false: it means that a number or a plus or minus sign has
                           been encountered
            */
            if (flag == true) {
                if (s[i] == ' ') {
                    ++start;
                    ++end;
                    continue;
                }
                else if (s[i] == '+' || s[i] == '-') {
                    ++bound;
                    ++end;
                    flag = false;
                    continue;
                }
                // not a space or a plus or minus or a number
                else if (isdigit(s[i]) == 0) {
                    return 0;
                }
                else {
                    flag = false;
                }
            }

            if (flag == false) {
                if (isdigit(s[i]) == 0) {
                    break;
                }
                ++end;
                // skip leading zeros
                if (zeroflag == true && s[i] == '0') {
                    continue;
                }
                zeroflag = false;
                ++bound;
                if (bound > 11) {
                    break;
                }
            }
        }

        // empty || exists only one char and it is not a digit
        if (start - end == 0 || (end-start == 1 && (s[start] == '+' || s[start] == '-'))) {
            return 0;
        }

        string numStr = s.substr(start, end-start);
        num = stoll(numStr);
        if (num < -2147483648)      return -2147483648;
        else if (num > 2147483647)  return 2147483647;

        return static_cast<int>(num);
    }
};

int main(int argc, char **argv) {
    /*
    Some examples
        in: " 123  12", out: "123"
        in: "   abc12", out: "0"
        in: "  123abc", out: "123"
        in: "-123", out: "-123"
        in: "--123", out: "0"
        in: "1145141919248", out: "2147483647"
        in: "  0000000000012345678", out: "12345678"
        in: "20000000000000000000", out: ""
    */
    string s = "-123";
    Solution sol;
    cout << sol.myAtoi(s) << endl;

    return 0;
}
