#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void clearTree(struct TreeNode *root) {
    if(root == NULL) {
        return;
    }
    clearTree(root->left);
    clearTree(root->right);
    free(root);
}

void inorderTravel(struct TreeNode *root) {
    if(root == NULL) {
        return;
    }
    inorderTravel(root->left);
    printf("%d ", root->val);
    inorderTravel(root->right);
}

void swap(int *l, int *r) {
    // if l == r, the XOR-based swap will set the value to zero
    if(*l != *r) {
        *l = *l ^ *r;
        *r = *r ^ *l;
        *l = *l ^ *r;
    }
}

void inorder(struct TreeNode *node, struct TreeNode **firs, struct TreeNode **seco, struct TreeNode **prev) {
    if(node == NULL) {
        return;
    }
    inorder(node->left, firs, seco, prev);
    if(*prev != NULL && node->val < (*prev)->val) {
        if(*firs == NULL) {
            *firs = *prev;
        }
        *seco = node;
    }
    *prev = node;
    inorder(node->right, firs, seco, prev);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root){
    struct TreeNode *firs = NULL;
    struct TreeNode *seco = NULL;
    struct TreeNode *prev = NULL;

    inorder(root, &firs, &seco, &prev);
    swap(&(firs->val), &(seco->val));
}

int main(int argc, char **argv) {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 2;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->val = 3;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->val = 1;
    root->right->left = NULL;
    root->right->right = NULL;
    
    inorderTravel(root);
    printf("\n---------\n");
    recoverTree(root);
    inorderTravel(root);
    printf("\n");
    
    clearTree(root);
    return 0;
}
