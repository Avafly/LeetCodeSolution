#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        vector<string> ans;
        rec(s, 0, 0, ip, ans);
        return ans;
    }
private:
    void rec(string &s, int start, int octet, string ip, vector<string> &ans) {
        if(start == s.size() && octet == 4) {
            ip.pop_back(); // erase the '.'
            ans.push_back(ip);
            return;
        }

        if((s.size() - start > (4 - octet) * 3) || (s.size() - start < (4 - octet))) {
            return;
        }

        int num = 0;
        for(int i = start; i < start + 3; ++i) {
            num = num * 10 + (s[i] - '0');
            if(num <= 255) {
                ip += s[i];
                rec(s, i + 1, octet + 1, ip + '.', ans);
            }
            if(num == 0) break;
        }
    }
};

int main(int argc, char **argv) {
    string s = "0000";
    
    Solution sol;
    vector<string> ans = sol.restoreIpAddresses(s);
    for(auto &str : ans) {
        cout << str << endl;
    }
    
    return 0;
}
