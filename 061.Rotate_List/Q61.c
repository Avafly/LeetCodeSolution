#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void createList(struct ListNode **list, int nums[], int size) {
    struct ListNode *tail = NULL;
    
    for(int i = 0; i < size; ++i) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = nums[i];
        newNode->next = NULL;

        if(!*list) {
            *list = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
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
struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *p = head;
    int len = listSize(head);
    if(len == 0) {
        return NULL;
    }
    // remove unnecessary repetitions
    k %= len;

    // create a vector to store the rotated ListNode
    int *temp = (int *)malloc(sizeof(int) * len);

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
    struct ListNode *ans = NULL;
    createList(&ans, temp, len);

    // free the memory
    free(temp);
    return ans;
}

int main(int argc, char **argv) {
    int k = 7;

    // create ListNode
    int nums[] = {1, 1, 4, 5, 1, 4};
    struct ListNode *list = NULL;
    createList(&list, nums, sizeof(nums) / sizeof(int));

    struct ListNode *ans = rotateRight(list, k);
    printList(ans);

    // free the memory
    clearList(list);
    clearList(ans);
    return 0;
}