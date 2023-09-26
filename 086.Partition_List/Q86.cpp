
// LeetCode Problem:
// Title: Partition List
// URL: https://leetcode.com/problems/partition-list/

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
    ListNode *partition(ListNode *head, int x) {
        if(x < -100 || x > 100) return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *p = dummy;
        ListNode *prev = dummy;
        ListNode *deleteP = nullptr;
        bool isX = false;
        
        while(p) {
            while(isX && p->next && p->next->val < x) {
                ListNode *tmp = prev->next;
                prev->next = p->next;
                p->next = p->next->next;
                prev->next->next = tmp;
                prev = prev->next;
            }
            if(!isX && p->next && p->next->val >= x) {
                isX = true;
            }
            p = p->next;
            if(!isX) prev = p;
        }

        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1,4,3,2,5,2};
    ListNode *head = createList(nums);
    int x = 3;
    
    Solution sol;
    ListNode *ans = sol.partition(head, x);
    printList(ans);
    
    /* free the memory */
    clearList(ans);
    return 0;
}