
// LeetCode Problem:
// Title: Simplify Path
// URL: https://leetcode.com/problems/simplify-path/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool myStrcmp(char *s1, char *s2, int n) {
    for(int i = 0; i < n; ++i) {
        if(s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

char * simplifyPath(char * path){
    int pathSize = strlen(path);
    if(pathSize == 1) return path;

    char *ans = (char *)calloc(pathSize + 1, sizeof(char));
    char *dirs[1500];
    int dirsSize = 0;
    int start = 0;

    for(int i = 0; i < pathSize; ++i) {
        if(i < pathSize - 1 && path[i + 1] == '/') {
            int n = i - start + 1;
            if(n == 3 && myStrcmp(path + start, "/..", n)) {
                start += 3;
                if(dirsSize != 0) {
                    free(dirs[dirsSize - 1]);
                    --dirsSize;
                }
            }
            else if(n == 1 && myStrcmp(path + start, "/", n)) {
                ++start;
            }
            else if(n == 2 && myStrcmp(path + start, "/.", n)) {
                start += 2;
            }
            else {
                dirs[dirsSize] = (char *)calloc(n + 1, sizeof(char));
                strncpy(dirs[dirsSize], path + start, n);
                ++dirsSize;
                start = i + 1;
            }
        }
        else if(i == pathSize - 1) {
            int n = i - start + 1;
            if(n == 3 && myStrcmp(path + start, "/..", n)) {
                if(dirsSize != 0) {
                    free(dirs[dirsSize - 1]);
                    --dirsSize;
                }
            }
            else if(!(n == 1 && myStrcmp(path + start, "/", n)) && !(n == 2 && myStrcmp(path + start, "/.", n))) {
                dirs[dirsSize] = (char *)calloc(n + 1, sizeof(char));
                strncpy(dirs[dirsSize], path + start, n);
                ++dirsSize;
            }
        }
    }

    if(dirsSize == 0) {
        ans[0] = '/';
    }
    else {
        int ansSize = 0;
        for(int i = 0; i < dirsSize; ++i) {
            int len = strlen(dirs[i]);
            memcpy(ans + ansSize, dirs[i], len);
            ansSize += len;
            free(dirs[i]);
        }
    }
    
    return ans;
}

int main(int argc, char **argv) {
    char *path = "/home/./doc";

    char *ans = simplifyPath(path);
    printf("%s\n", ans);

    free(ans);
    return 0;
}
