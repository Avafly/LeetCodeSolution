#include <stdio.h>
#include <stdlib.h>

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
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(left == right) return head;
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *rLeft = NULL;
    struct ListNode *rRight = NULL;
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

int main(int argc, char **argv) {
    int nums[] = {5};
    int left = 1;
    int right = 1;
    struct ListNode *head = createList(nums, sizeof(nums) / sizeof(int));
    
    struct ListNode *ans = reverseBetween(head, left, right);
    printList(ans);
    
    clearList(ans);
    return 0;
}
