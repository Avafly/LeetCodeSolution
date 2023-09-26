// LeetCode Problem:
// Title: Add Two Numbers
// URL: https://leetcode.com/problems/add-two-numbers/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createList(int nums[], int size) {
    struct ListNode *list = NULL;
    struct ListNode *tail = NULL;

    for(int i = 0; i < size; ++i) {
        struct ListNode *newNode = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        newNode->val = nums[i];

        if(!list) {
            list = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return list;
}

void printList(struct ListNode *list) {
    struct ListNode *p = list;
    
    while(p) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
}


void clearList(struct ListNode *list) {
    struct ListNode *p = list;
    
    while(p) {
        struct ListNode *deleteP = p;
        p = p->next;
        free(deleteP);
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {

    struct ListNode *p = NULL;
    struct ListNode *ans = NULL;
    struct ListNode *pTail = NULL;

    int carry = 0;
    int sum = 0;

    // linked list is not empty or hasn't not handle exist carry.
    while(l1 != NULL || l2!=NULL || carry != 0) {
        sum = carry;

        // add node's values
        if(l1 != NULL) {
            sum = sum + l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum = sum + l2->val;
            l2 = l2->next;
        }
        // compute carry and sum
        carry = sum / 10;
        sum = sum - carry * 10;

        // create a new node and assign a number
        p = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        p->val = sum;
        if(!ans) {
            ans = p;
            pTail = p;
        }
        else {
            pTail->next = p;
            pTail = pTail->next;
        }
    }

    return ans;
}

int main(int argc, char **argv) {

    int nums1[] = {2, 4, 3};
    int nums2[] = {5, 6, 4};
    
    struct ListNode *l1 = createList(nums1, sizeof(nums1) / sizeof(int));
    struct ListNode *l2 = createList(nums2, sizeof(nums2) / sizeof(int));

    struct ListNode *ans = addTwoNumbers(l1, l2);
    printList(ans);
    clearList(l1);
    clearList(l2);
    clearList(ans);

    return 0;
}
