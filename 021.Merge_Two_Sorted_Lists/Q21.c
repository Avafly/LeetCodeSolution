
// LeetCode Problem:
// Title: Merge Two Sorted Lists
// URL: https://leetcode.com/problems/merge-two-sorted-lists/

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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode *ans = NULL;
    struct ListNode *p = NULL;

    while(list1 != NULL || list2 != NULL) {
        if(list1 != NULL && list2 != NULL) {
            if(ans == NULL) {
                ans = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = ans;
            }
            else {
                p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = p->next;
            }
            p->next = NULL;
            if(list1->val < list2->val) {
                p->val = list1->val;
                list1 = list1->next;
            }
            else {
                p->val = list2->val;
                list2 = list2->next;
            }
        }
        else if(list1!=NULL && list2==NULL) {
            if(ans == NULL) {
                ans = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = ans;
            }
            else {
                p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = p->next;
            }
            p->next = NULL;
            p->val = list1->val;
            list1 = list1->next;
        }
        else if(list1==NULL && list2!=NULL) {
            if(ans == NULL) {
                ans = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = ans;
            }
            else {
                p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = p->next;
            }
            p->next = NULL;
            p->val = list2->val;
            list2 = list2->next;
        }
    }

    return ans;
}

int main(int argc, char **argv) {
    int input1[] = {1, 2, 4};
    int input2[] = {1, 3, 5};
    
    struct ListNode *l1 = createList(input1, sizeof(input1) / sizeof(int));
    struct ListNode *l2 = createList(input2, sizeof(input2) / sizeof(int));

    struct ListNode *ans = mergeTwoLists(l1, l2);
    printList(ans);

    clearList(l1);
    clearList(l2);
    clearList(ans);

    return 0;
}
