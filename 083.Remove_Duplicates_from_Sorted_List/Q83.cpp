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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p = head->next;
        ListNode *prev = head;
        ListNode *deleteP = nullptr;
        bool isDelete = false;
        
        while(p) {
            if(prev->val != p->val) {
                prev->next = p;
                prev = p;
                isDelete = false;
            }
            else {
                isDelete = true;
                deleteP = p;
            }
            p = p->next;
            if(isDelete) delete deleteP;
        }
        if(isDelete) prev->next = nullptr;
        
        return head;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1,1,2,2,3,3,3,3,3};
    ListNode *head = createList(nums);

    Solution sol;
    ListNode *ans = sol.deleteDuplicates(head);
    printList(ans);
    
    /* free the memory */
    clearList(ans);
    return 0;
}