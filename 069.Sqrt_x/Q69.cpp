#include <iostream>
using namespace std;

// binary search
class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)  return 1;

        int l = 0;
        int r = x;
        while(l < r) {
            long mid = (l + r) / 2;
            if(mid * mid > x) {
                r = mid;
            }
            else {
                l = mid;
            }
            // r - l == 1 means l < sqrt(x) < r
            if(r - l == 1) {
                break;
            }
        }
        return l;
    }
};

int main(int argc, char ** argv) {
    int x = 2147395599;
    Solution sol;
    cout << sol.mySqrt(x) << endl;
    return 0;
}