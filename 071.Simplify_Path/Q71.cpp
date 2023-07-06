#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int pathSize = path.size();
        if(pathSize == 1)  return path;
        string ans;
        vector<string> dirs;
        int start = 0;

        for(int i = 0; i < pathSize; ++i) {
            if(i < pathSize - 1 && path[i + 1] == '/') {
                string str = path.substr(start, i - start + 1);
                if(str == "/..") {
                    start += 3;
                    if(!dirs.empty()) {
                        dirs.pop_back();
                    }
                }
                else if(str == "/") {
                    ++start;
                }
                else if(str == "/.") {
                    start += 2;
                }
                else {
                    dirs.push_back(str);
                    start = i + 1;
                }
            }
            else if(i == pathSize - 1) {
                string str = path.substr(start, i - start + 1);
                if(str == "/..") {
                    if(!dirs.empty()) {
                        dirs.pop_back();
                    }
                }
                else if(str != "/" && str != "/.") {
                    dirs.push_back(str);
                }
            }
        }
        
        if(dirs.empty()) {
            ans.push_back('/');
        }
        else {
            for(auto &dir : dirs) {
                ans.append(dir);
            }
        }


        return ans;
    }
};

int main(int argc, char **argv) {
    vector<string> paths = {
        "/home/",
        "/home.foo/.",
        "/home/./doc",
        "/home/../doc",
        "/../",
        "/home//foo/...",
        "///"
    };

    Solution sol;
    for(auto &path : paths) {
        cout << sol.simplifyPath(path) << endl;
        cout << "------------" << endl;
    }

    return 0;
}
