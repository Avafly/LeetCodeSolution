#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void print_LinkedList(struct ListNode* l) {
    struct ListNode* p = NULL;

    while (l!=NULL) {
        p = l;
        l = l->next;

        printf("%d ", p->val);
    }
    printf("\n");
}

void free_LinkedList(struct ListNode* l) {
    struct ListNode* p = NULL;

    while (l!=NULL) {
        p = l;
        l = l->next;

        free(p);
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0) return NULL;

    int nums[20000] = {0};
    int offset = 10000;
    struct ListNode *p = NULL;
    struct ListNode *ans = NULL;
    int isFirst = 1;

    for(int i=0; i<listsSize; ++i) {
        p = lists[i];
        while(p != NULL) {
            int idx = p->val + offset;
            ++nums[idx];
            p = p->next;
        }
    }

    for(int i=0; i<20000; ++i) {
        while(nums[i] != 0) {
            if(isFirst) {
                ans = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = ans;
                p->val = i - offset;
                p->next = NULL;
                isFirst = 0;
            }
            else {
                p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = p->next;
                p->val = i - offset;
                p->next = NULL;
            }
            --nums[i];
        }
    }


    return ans;
}

int main(int argc, char **argv) {

    struct ListNode *p;
    struct ListNode **input = (struct ListNode**)malloc(3*sizeof(struct ListNode*));
    input[0] = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = input[0];
    p->val = 1;
    p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 4;
    p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 5;
    p->next = NULL;

    input[1] = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = input[1];
    p->val = 1;
    p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 3;
    p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 4;
    p->next = NULL;

    input[2] = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = input[2];
    p->val = 2;
    p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = p->next;
    p->val = 6;
    p->next = NULL;

    struct ListNode *ans = mergeKLists(input, 3);

    //print_LinkedList(input[0]);
    //print_LinkedList(input[1]);
    //print_LinkedList(input[2]);
    print_LinkedList(ans);

    free_LinkedList(input[0]);
    free_LinkedList(input[1]);
    free_LinkedList(input[2]);
    free(input);

    return 0;
}