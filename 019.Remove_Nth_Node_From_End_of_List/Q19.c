
// LeetCode Problem:
// Title: Remove Nth Node From End of List
// URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createList(int nums[], int size) {
    struct ListNode *list = NULL;
    struct ListNode *tail = NULL;

    for(int i = 0; i < size; ++i) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = nums[i];
        newNode->next = NULL;

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *fir = dummy;
    struct ListNode *sec = dummy;
    for(int i = 1; i <= n + 1; i++) {
        fir = fir->next;
    }
    while(fir != NULL) {
        fir = fir->next;
        sec = sec->next;
    }
    struct ListNode *tmp = sec->next;
    sec->next = sec->next->next;
    struct ListNode *ans = dummy->next;
    free(tmp);
    free(dummy);
    return ans;
}

int main(int argc, char **argv) {
    int list[] = {1,1,4,5,1,4};
    struct ListNode *head = createList(list, sizeof(list) / sizeof(int));
    int n = 1;
    struct ListNode *ans = removeNthFromEnd(head, n);

    printList(ans);
    clearList(ans);

    return 0;
}
