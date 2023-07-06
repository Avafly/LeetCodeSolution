#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *list) {
    ListNode *p = list;
    while(p != nullptr) {
        std::cout << p->val;
        if(p->next != nullptr) {
            std::cout << " -> ";
        }
        p = p->next;
    }
    std::cout << std::endl;
}

void clearList(ListNode *list) {
    ListNode *p = list;
    ListNode *deleteP = nullptr;

    while(p != nullptr) {
        deleteP = p;
        p = p->next;
        delete deleteP;
    }
}

ListNode *createList(const vector<int> &nums) {
    if(nums.empty()) {
        return nullptr;
    }
    ListNode *list = new ListNode(nums[0]);
    ListNode *p = list;
    for(size_t i = 1; i < nums.size(); ++i) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return list;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = nullptr;
        ListNode *p = nullptr;
        int isFirst = 1;
        int newNode = 0;

        while(list1 != nullptr || list2 != nullptr) {
            if(list1 != nullptr && list2 != nullptr) {
                if(list1->val < list2->val) {
                    newNode = list1->val;
                    list1 = list1->next;
                }
                else {
                    newNode = list2->val;
                    list2 = list2->next;
                }
            }
            else if(list1 != nullptr && list2 == nullptr) {
                newNode = list1->val;
                list1 = list1->next;
            }
            else if(list1 == nullptr && list2 != nullptr) {
                newNode = list2->val;
                list2 = list2->next;
            }
            if(isFirst == 1) {
                ans = new ListNode(newNode);
                p = ans;
                isFirst = 0;
            }
            else {
                p->next = new ListNode(newNode);
                p = p->next;
            }
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    vector<int> input1({1, 2, 4});
    vector<int> input2({1, 3, 4});
    ListNode *l1 = createList(input1);
    ListNode *l2 = createList(input2);

    Solution sol = Solution();
    ListNode *ans = sol.mergeTwoLists(l1, l2);
    
    printList(ans);
    clearList(l1);
    clearList(l2);
    clearList(ans);

    return 0;
}
