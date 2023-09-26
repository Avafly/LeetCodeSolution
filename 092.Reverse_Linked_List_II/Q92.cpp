
// LeetCode Problem:
// Title: Reverse Linked List II
// URL: https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if(left == right) return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *rLeft = NULL;
        ListNode *rRight = NULL;
        int count = 1;
        
        for(; count <= right; ++count) {
            // store the address of first reversed element and its previous element
            if(count == left) {
                rLeft = prev;
                rRight = curr;
                prev = curr;
                curr = curr->next;
            }
            else if(count > left) {
                struct ListNode *tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        if(count == right + 1) {
            rRight->next = curr;
            if(rLeft)
                rLeft->next = prev;
            else
                head = prev;
        }
        return head;
    }
};

int main(int argc, char **argv) {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = createList(nums);
    int left = 2, right = 4;
    
    Solution sol;
    ListNode *ans = sol.reverseBetween(head, left, right);
    printList(ans);
    clearList(ans);
    
    return 0;
}
