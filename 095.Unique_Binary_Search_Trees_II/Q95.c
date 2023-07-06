#include <stdio.h>
#include <stdlib.h>

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

struct TreeNode **generateTreesFromRange(int start, int end, int *returnSize) {
    if(start > end) {
        *returnSize = 1;
        struct TreeNode **nullNodeList = malloc(sizeof(struct TreeNode*));
        nullNodeList[0] = NULL;
        return nullNodeList;
    }
    
    int totalSize = 0;
    struct TreeNode **totalTrees = NULL;
    for(int i = start; i <= end; ++i) {
        int leftSize, rightSize;
        struct TreeNode **leftTrees = generateTreesFromRange(start, i - 1, &leftSize);
        struct TreeNode **rightTrees = generateTreesFromRange(i + 1, end, &rightSize);
        
        for(int p = 0; p < leftSize; ++p) {
            for(int q = 0; q < rightSize; ++q) {
                struct TreeNode *root = malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = leftTrees[p];
                root->right = rightTrees[q];
                
                totalSize++;
                totalTrees = realloc(totalTrees, totalSize * sizeof(struct TreeNode*));
                totalTrees[totalSize - 1] = root;
            }
        }
        
        free(leftTrees);
        free(rightTrees);
    }
    
    *returnSize = totalSize;
    return totalTrees;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTrees(int n, int* returnSize){
    if(n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesFromRange(1, n, returnSize);
}

int main(int argc, char **argv) {
    int n = 3;
    int returnSize = 0;
    struct TreeNode **ans = generateTrees(n, &returnSize);
    for(int i = 0; i < returnSize; ++i) {
        inorderTraversal(ans[i]);
        clearTree(ans[i]);
        printf("\n");
    }
    free(ans);

    return 0;
}
