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

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(k == 1) return head;

    int len = 0;

    struct ListNode *nodes[5000] = {NULL};
    struct ListNode *tmp = head;

    // record pointers of nodes
    while(tmp != NULL) {
        nodes[len++] = tmp;
        tmp = tmp->next;
    }

    for(int i=(k-1); i<len; i+=k) {
        int start = i - k + 1;
        int end = i;
        while(start < end) {
            // swap
            if(start+1 == end) {
                nodes[start]->next = nodes[end]->next;
                nodes[end]->next = nodes[start];
                if(start != 0) {
                    nodes[start-1]->next = nodes[end];
                }
                tmp = nodes[end];
                nodes[end] = nodes[start];
                nodes[start] = tmp;
            }
            else {
                tmp = nodes[end]->next;
                nodes[end]->next = nodes[start]->next;
                nodes[start]->next = tmp;
                if(start != 0) {
                    nodes[start-1]->next = nodes[end];
                }
                nodes[end-1]->next = nodes[start];
                tmp = nodes[end];
                nodes[end] = nodes[start];
                nodes[start] = tmp;
            }

            ++start;
            --end;
        }
    }
    return nodes[0];
}

int main(int argc, char **argv) {

    int list[] = {1, 2, 3, 4, 5};
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

    int k = 3;

    print_LinkedList(head);

    struct ListNode *ans = reverseKGroup(head, k);

    //print_LinkedList(head);
    print_LinkedList(ans);

    //free_LinkedList(head);
    free_LinkedList(ans);

    return 0;
}