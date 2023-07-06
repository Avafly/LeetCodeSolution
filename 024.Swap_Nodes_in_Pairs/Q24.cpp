#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void clearList(ListNode* list) {
    ListNode* p = list;
    ListNode* deleteP = nullptr;

    while (p != nullptr) {
        deleteP = p;
        p = p->next;
        delete(deleteP);
    }
}

void printList(ListNode* list) {
    ListNode* p = list;

    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int even = 0;
        int isFirst = 1;
        ListNode *p = head;
        ListNode *pPrev = nullptr;
        ListNode *tmp = nullptr;
        ListNode *lastSwap = nullptr;

        while(p != nullptr) {
            if(even) {
                pPrev->next = p->next;
                p->next = pPrev;
                // swap p and pPrev
                tmp = p;
                p = pPrev;
                pPrev = tmp;
                if(isFirst) {
                    head = pPrev;
                    isFirst = 0;
                }
                else {
                    lastSwap->next = pPrev;
                }
                lastSwap = p;

                p = p->next;
            }
            else {
                pPrev = p;
                p = p->next;
            }

            even = !even;
        }

        return head;
    }
};

int main(int argc, char **argv) {

    int arr[] = {1, 2, 3, 4};
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

    Solution sol = Solution();

    ListNode *ans = sol.swapPairs(list);

    printList(ans);

    clearList(ans);




    return 0;
}