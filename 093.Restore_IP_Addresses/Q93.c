
// LeetCode Problem:
// Title: Restore IP Addresses
// URL: https://leetcode.com/problems/restore-ip-addresses/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rec(char *s, int index, int octet, char *ip, int ipIndex, char **res, int *returnSize) {
    if(octet == 4) {
        if(s[index] == '\0') {
            ip[ipIndex - 1] = '\0';
            res[*returnSize] = (char *)calloc(strlen(ip) + 1, sizeof(char));
            strcpy(res[*returnSize], ip);
            ++(*returnSize);
        }
        return;
    }

    int num = 0;
    for(int i = 0; i < 3; ++i) {
        if(s[index + i] == '\0') { break; }
        num = num * 10 + (s[index + i] - '0');
        if(num <= 255) {
            ip[ipIndex + i] = s[index + i];
            ip[ipIndex + i + 1] = '.';
            rec(s, index + i + 1, octet + 1, ip, ipIndex + i + 2, res, returnSize);
        }
        if(num == 0) { break; }
    }
}

char **restoreIpAddresses(char *s, int *returnSize) {
    char **res = (char **)calloc(19, sizeof(char *));
    *returnSize = 0;

    char ip[17];
    rec(s, 0, 0, ip, 0, res, returnSize);

    return res;
}

int main() {
    char s[] = "101023";
    int returnSize;
    char **ans = restoreIpAddresses(s, &returnSize);

    for(int i = 0; i < returnSize; ++i) {
        printf("%s\n", ans[i]);
        free(ans[i]);
    }
    free(ans);

    return 0;
}
