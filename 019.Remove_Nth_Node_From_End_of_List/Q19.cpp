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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *fir = dummy;
        ListNode *sec = dummy;
        for(int i = 1; i <= n + 1; i++) {
            fir = fir->next;
        }
        while(fir != nullptr) {
            fir = fir->next;
            sec = sec->next;
        }
        ListNode *tmp = sec->next;
        sec->next = sec->next->next;
        ListNode *ans = dummy->next;
        delete tmp;
        delete dummy;
        return ans;
    }
};

int main(int argc, char **argv) {
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *nums = createList(arr);

    Solution sol = Solution();
    int n = 2;
    ListNode *ans = sol.removeNthFromEnd(nums, n);

    printList(ans);
    clearList(ans);

    return 0;
}
