#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createList(int nums[], int size) {
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
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head || !head->next) return head;
    struct ListNode *p = head->next;
    struct ListNode *prev = head;
    struct ListNode *deleteP = NULL;
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
        if(isDelete) free(deleteP);
    }
    if(isDelete) prev->next = NULL;
    
    return head;
}

int main(int argc, char **argv) {
    int nums[] = {1,2,3,3,3,3,4};
    struct ListNode *head = createList(nums, sizeof(nums) / sizeof(int));

    struct ListNode *ans = deleteDuplicates(head);
    printList(ans);

    /* free the memory */
    clearList(ans);
    return 0;
}
