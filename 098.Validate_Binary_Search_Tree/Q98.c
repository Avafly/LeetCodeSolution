
// LeetCode Problem:
// Title: Validate Binary Search Tree
// URL: https://leetcode.com/problems/validate-binary-search-tree/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isValid(struct TreeNode *root, struct TreeNode *minNode, struct TreeNode *maxNode) {
    if(root == NULL) {
        return true;
    }
    if(minNode != NULL && root->val <= minNode->val) {
        return false;
    }
    if(maxNode != NULL && root->val >= maxNode->val) {
        return false;
    }
    return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode *root){
    return isValid(root, NULL, NULL);
}

int main(int argc, char **argv) {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 2;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->val = 1;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    
    printf("%s\n", isValidBST(root) ? "True" : "False");
    
    clearTree(root);
    return 0;
}
