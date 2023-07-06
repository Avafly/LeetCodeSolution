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

    while (p != nullptr) {
        deleteP = p;
        p = p->next;
        delete(deleteP);
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head;
        int len = listSize(head);
        if(len == 0) {
            return nullptr;
        }
        // remove unnecessary repetitions
        k = k % len;

        // create a vector to store the rotated ListNode
        vector<int> temp(len, 0);

        // start from k-th index
        for(int i = k; i < len; ++i) {
            temp[i] = p->val;
            p = p->next;
        }
        // start from first index
        for(int i = 0; i < k; ++i) {
            temp[i] = p->val;
            p = p->next;
        }

        // create answer
        ListNode *ans = createList(temp);
        return ans;
    }

private:
    int listSize(ListNode *list) {
        ListNode *p = list;
        int len = 0;
        while(p != nullptr) {
            ++len;
            p = p->next;
        }
        return len;
    }
};

int main(int argc, char **argv) {
    int k = 10;
    
    // create ListNode *head
    vector<int> nums = {1,2,3,4,5};
    ListNode *head = createList(nums);

    Solution sol = Solution();

    ListNode *ans = sol.rotateRight(head, k);

    printList(ans);
    clearList(ans);
    clearList(head);
    return 0;
}