
// LeetCode Problem:
// Title: Partition List
// URL: https://leetcode.com/problems/partition-list/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int listSize(struct ListNode *list) {
    struct ListNode *p = list;
    int len = 0;
    while(p != NULL) {
        ++len;
        p = p->next;
    }
    return len;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *partition(struct ListNode *head, int x){
    if(x < -100 || x > 100) return head;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *p = dummy;
    struct ListNode *prev = dummy;
    struct ListNode *deleteP = NULL;
    bool isX = false;
    
    while(p) {
        while(isX && p->next && p->next->val < x) {
            struct ListNode *tmp = prev->next;
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
    
    struct ListNode *ans = dummy->next;
    free(dummy);
    return ans;
}

int main(int argc, char **argv) {
    int nums[] = {1,4,3,2,5,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    struct ListNode *head = createList(nums, numsSize);
    
    int x = 3;
    struct ListNode *ans = partition(head, x);
    printList(ans);
    
    /* free the memory */
    clearList(ans);
    return 0;
}
