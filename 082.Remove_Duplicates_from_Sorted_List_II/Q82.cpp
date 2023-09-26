
// LeetCode Problem:
// Title: Remove Duplicates from Sorted List II
// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *p = head;
        ListNode *deleteP = nullptr;

        while(p) {
            bool isDelete = false;
            while(p->next && p->val == p->next->val) {
                isDelete = true;
                deleteP = p;
                p = p->next;
                delete deleteP;
            }
            if(isDelete) {
                deleteP = p;
                prev->next = p->next;
            }
            else {
                prev = p;
            }
            p = p->next;
            
            if(isDelete) {
                delete deleteP;
            }
        }

        ListNode *ans = dummy->next;
        delete dummy;
        
        return ans;
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