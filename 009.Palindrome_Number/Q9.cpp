#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        int num = x;
        long rev = 0;
        while(x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return num == rev;
    }
};

int main(int argc, char **argv) {
    int x = 10;
    Solution sol;
    cout << sol.isPalindrome(x) << endl;

    return 0;
}
