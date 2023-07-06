#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0) return nullptr;
        
        vector<int> nums;

        ListNode *p = nullptr;
        ListNode *ans = nullptr;

        int isFirst = 1;

        for(int i=0; i<len; ++i) {
            p = lists[i];
            while(p != nullptr) {
                nums.push_back(p->val);
                p = p->next;
            }
        }

        if(!nums.empty()) {
            sort(nums.begin(), nums.end());

            for(int i=0; i<nums.size(); ++i) {
                if(isFirst) {
                    ans = new ListNode(nums[i]);
                    p = ans;
                    isFirst = 0;
                }
                else {
                    p->next = new ListNode(nums[i]);
                    p = p->next;
                }
            }

            return ans;
        }
        else {
            return nullptr;
        }
    }
};

int main() {

    vector<ListNode*> lists;
    ListNode *p;

    // list1
    ListNode *list1 = new ListNode(1);
    p = new ListNode(4);
    list1->next = p;
    p->next = new ListNode(5);
    // list2
    ListNode *list2 = new ListNode(1);
    p = new ListNode(3);
    list2->next = p;
    p->next = new ListNode(4);
    // list3
    ListNode *list3 = new ListNode(2);
    p = new ListNode(6);
    list3->next = p;

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    Solution sol = Solution();
    ListNode *ans = sol.mergeKLists(lists);

    //printList(lists[0]);
    //printList(lists[1]);
    //printList(lists[2]);
    printList(ans);

    clearList(lists[0]);
    clearList(lists[1]);
    clearList(lists[2]);
    clearList(ans);

    return 0;
}