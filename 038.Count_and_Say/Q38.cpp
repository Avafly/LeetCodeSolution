#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        
        for(int i = 2; i <= n; ++i) {
            string curr = "";
            int count = 1;
            
            for(int j = 1; j < ans.size(); ++j) {
                if(ans[j] == ans[j - 1]) {
                    ++count;
                }
                else {
                    curr += to_string(count) + ans[j - 1];
                    count = 1;
                }
            }
            
            curr += to_string(count) + ans.back();
            ans = curr;
        }
        
        return ans;
    }
};

int main(int argc, char **argv) {
    int n = 15;
    Solution sol;
    cout << sol.countAndSay(n) << endl;
    return 0;
}
