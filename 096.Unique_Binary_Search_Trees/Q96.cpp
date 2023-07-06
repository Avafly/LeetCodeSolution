#include <iostream>
#include <vector>

/*
 Idea
 Support G(n) as the number of unique BSTs for a sequence of length n, and f(i)
 as the number of unique BSTs where i is the root.
 Then, G(n) = f(1) + f(2) + f(3) + ... + f(n).
 Therefore, G(n) = G(0)*G(n-1)+G(1)*G(n-2)+...+G(n-1)*G(0).
 */

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main(int argc, char **argv) {
    int n = 15;
    Solution sol;
    cout << sol.numTrees(n) << endl;
    return 0;
}
