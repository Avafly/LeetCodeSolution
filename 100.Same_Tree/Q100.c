#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1430

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderTraversal(struct TreeNode *root) {
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

void clearTree(struct TreeNode *root) {
    if(root == NULL) {
        return;
    }
    clearTree(root->left);
    clearTree(root->right);
    free(root);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL || q == NULL) {
        return p == NULL && q == NULL;
    }
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char **argv) {
    // create p
    struct TreeNode *p = malloc(sizeof(struct TreeNode));
    p->val = 1;
    p->left = malloc(sizeof(struct TreeNode));
    p->right = malloc(sizeof(struct TreeNode));
    p->left->val = 2;
    p->left->left = NULL;
    p->left->right = NULL;
    p->right->val = 3;
    p->right->left = NULL;
    p->right->right = NULL;
    // create q
    struct TreeNode *q = malloc(sizeof(struct TreeNode));
    q->val = 1;
    q->left = malloc(sizeof(struct TreeNode));
    q->right = malloc(sizeof(struct TreeNode));
    q->left->val = 2;
    q->left->left = NULL;
    q->left->right = NULL;
    q->right->val = 3;
    q->right->left = NULL;
    q->right->right = NULL;
    
    printf("%s\n", isSameTree(p, q) == true ? "True" : "False");
    
    /* free  the memory */
    clearTree(p);
    clearTree(q);

    return 0;
}
