#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) {
            return 0;
        }
        long ans = 0;
        long dd = dividend;
        long dr = divisor;
        int neg = (dd > 0) ^ (dr > 0);

        dd = labs(dd);
        dr = labs(dr);
        if(dr == 1) {
            ans = dd;
        }
        else {
            for(int i = 31; i >= 0; --i) {
                if(dr<<i <= dd) {
                    dd -= dr << i;
                    ans += 1 << i;
                }
            }
        }
        ans = neg ? -ans : ans;

        if(ans > 2147483647) {
            return 2147483647;
        }
        if(ans < -2147483648) {
            return -2147483648;
        }
        return static_cast<int>(ans);
    }
};

int main(int argc, char **argv) {
    int dividend = 10, divisor = 3;
    Solution sol;
    cout << sol.divide(dividend, divisor) << endl;
    return 0;
}
