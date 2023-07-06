#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int prevSpace = n;
        int i;
        for(i = n - 1; i >= 0; --i) {
            // skip consecutive spaces
            if(s[i] == ' ') {
                if(prevSpace - i == 1) {
                    prevSpace = i;
                }
                else {
                    return prevSpace - i - 1;
                }
            }
        }

        return i == -1 ? prevSpace : prevSpace - i - 1;
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();
    string s = " aaaaa";

    cout << sol.lengthOfLastWord(s) << endl;

    return 0;
}