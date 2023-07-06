#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void freeTree(struct TreeNode *root) {
    if(root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void rec(struct TreeNode *root, int *ans, int *returnSize) {
    if(root == NULL) {
        return;
    }
    rec(root->left, ans, returnSize);
    ans[(*returnSize)++] = root->val;
    rec(root->right, ans, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *ans = (int *)calloc(100, sizeof(int));
    *returnSize = 0;
    rec(root, ans, returnSize);
    return ans;
}

int main(int argc, char **argv) {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = 2;
    root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->right = NULL;
    root->right->left->val = 3;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    
    int returnSize;
    int *ans = inorderTraversal(root, &returnSize);
    for(int i = 0; i < returnSize; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    /* free the memory */
    free(ans);
    freeTree(root);
    return 0;
}
