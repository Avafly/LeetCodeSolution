#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int ai = a.size() - 1, bi = b.size() - 1;
        int carry = 0;
        string ans = "";

        while(ai >= 0 || bi >= 0 || carry) {
            int sum = carry;
            carry = 0;

            if(ai >= 0 && bi >= 0) {
                sum += a[ai] - '0' + b[bi] - '0';
                --ai;
                --bi;
            }
            else if(ai >= 0) {
                sum += a[ai] - '0';
                --ai;
            }
            else if(bi >= 0) {
                sum += b[bi] - '0';
                --bi;
            }
            carry = sum / 2;
            ans.insert(ans.begin(), static_cast<char>((sum % 2) + '0'));
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();

    string a = "0";
    string b = "0";

    cout << sol.addBinary(a, b) << endl;

    return 0;
}