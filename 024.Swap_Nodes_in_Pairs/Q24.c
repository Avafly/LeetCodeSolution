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

struct ListNode* swapPairs(struct ListNode* head){
    int even = 0;
    int isFirst = 1;

    struct ListNode *p = head;
    struct ListNode *pPrev = NULL;
    struct ListNode *tmp = NULL;
    struct ListNode *lastSwap = NULL;

    while(p != NULL) {

        if(even) {
            pPrev->next = p->next;
            p->next = pPrev;
            // swap p and pPrev
            tmp = p;
            p = pPrev;
            pPrev = tmp;
            if(isFirst) {
                head = pPrev;
                isFirst = 0;
            }
            else {
                lastSwap->next = pPrev;
            }
            lastSwap = p;

            p = p->next;
        }
        else {
            pPrev = p;
            p = p->next;
        }

        even = !even;
    }
    return head;
}

int main(int argc, char **argv) {

    int list[] = {1, 2, 3, 4};
    int isFirst = 1;
    struct ListNode *head = NULL;
    struct ListNode *p = NULL;

    for(int i=0; i<sizeof(list)/sizeof(int); ++i) {
        if(isFirst) {
            head = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = head;
            p->val = list[i];
            p->next = NULL;
            isFirst = 0;
        }
        else {
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = p->next;
            p->val = list[i];
            p->next = NULL;
        }
    }

    struct ListNode *ans = swapPairs(head);

    //print_LinkedList(head);
    print_LinkedList(ans);

    //free_LinkedList(head);
    free_LinkedList(ans);


    return 0;
}