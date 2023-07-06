#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void clearList(ListNode *list) {
    ListNode *p = list;
    ListNode *deleteP = nullptr;

    while (p != nullptr) {
        deleteP = p;
        p = p->next;
        delete(deleteP);
    }
}

void printList(ListNode *list) {
    ListNode *p = list;

    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;

        int len = 0;
        ListNode *nodes[5000] = {NULL};
        ListNode *tmp = head;

        while(tmp != nullptr) {
            nodes[len++] = tmp;
            tmp = tmp->next;
        }

        for(int i=(k-1); i<len; i+=k) {
            int start = i - k + 1;
            int end = i;
            while(start < end) {
                // swap
                if(start+1 == end) {
                    nodes[start]->next = nodes[end]->next;
                    nodes[end]->next = nodes[start];
                    if(start != 0) {
                        nodes[start-1]->next = nodes[end];
                    }
                    tmp = nodes[end];
                    nodes[end] = nodes[start];
                    nodes[start] = tmp;
                }
                else {
                    tmp = nodes[end]->next;
                    nodes[end]->next = nodes[start]->next;
                    nodes[start]->next = tmp;
                    if(start != 0) {
                        nodes[start-1]->next = nodes[end];
                    }
                    nodes[end-1]->next = nodes[start];
                    tmp = nodes[end];
                    nodes[end] = nodes[start];
                    nodes[start] = tmp;
                }

                ++start;
                --end;
            }
        }
        return nodes[0];
    }
};

int main(int argc, char **argv) {

    int arr[] = {1, 2, 3, 4, 5};
    ListNode *p = nullptr;
    ListNode *list = nullptr;
    int isFirst = 1;

    for(int i=0; i<sizeof(arr)/sizeof(int); ++i) {
        if(isFirst) {
            list = new ListNode(arr[i]);
            p = list;
            isFirst = 0;
        }
        else {
            p->next = new ListNode(arr[i]);
            p = p->next;
        }
    }

    printList(list);
    int k = 2;

    Solution sol = Solution();
    ListNode *ans = sol.reverseKGroup(list, k);

    printList(ans);

    clearList(ans);

    return 0;
}