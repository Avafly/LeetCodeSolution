// LeetCode Problem:
// Title: Add Two Numbers
// URL: https://leetcode.com/problems/add-two-numbers/

#include <iostream>
#include <string>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *pHead = nullptr;
        ListNode *pTail = nullptr;
        ListNode *p = nullptr;

        // Loop to extract the value in list node
        while (p1 != nullptr || p2 != nullptr || carry != 0) {

            // use carry
            sum = carry;

            // add node's value
            if (p1 != nullptr) {
                sum = sum + p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                sum = sum + p2->val;
                p2 = p2->next;
            }
            // compute carry and sum
            carry = sum / 10;
            sum -= carry * 10;

            // create nodes
            // only for the first node
            if (!pHead) {
                pHead = new ListNode(sum, nullptr);
                pTail = pHead;
            }
            // other nodes
            else {
                p = new ListNode(sum, nullptr);
                pTail->next = p;
                pTail = p;
            }

        }

        return pHead;
    }
};

int main(int argc, char **argv) {

    vector<int> nums1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> nums2 = {9, 9, 9, 9};

    ListNode *l1 = createList(nums1);
    ListNode *l2 = createList(nums2);

    Solution sol;
    ListNode *ans = sol.addTwoNumbers(l1, l2);
    printList(ans);
    
    // free the memory
    clearList(l1);
    clearList(l2);
    clearList(ans);

    return 0;
}
