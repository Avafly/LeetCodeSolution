
// LeetCode Problem:
// Title: Recover Binary Search Tree
// URL: https://leetcode.com/problems/recover-binary-search-tree/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insert(TreeNode *root, int val) {
    if(root == nullptr) {
        return new TreeNode(val);
    }
    if(val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void clearTree(TreeNode *root) {
    if(root == nullptr) {
        return;
    }
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

void inorderTravel(TreeNode *root) {
    if(root == nullptr) {
        return;
    }
    inorderTravel(root->left);
    cout << root->val << " ";
    inorderTravel(root->right);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *firs = nullptr;
        TreeNode *seco = nullptr;
        TreeNode *prev = nullptr;

        inorder(root, &firs, &seco, &prev);
        swap(firs->val, seco->val);
    }
    
    void inorder(TreeNode *node, TreeNode **firs, TreeNode **seco, TreeNode **prev) {
        if(node == nullptr) {
            return;
        }
        inorder(node->left, firs, seco, prev);
        if(*prev != nullptr && node->val < (*prev)->val) {
            if(*firs == nullptr) {
                *firs = *prev;
            }
            *seco = node;
        }
        *prev = node;
        inorder(node->right, firs, seco, prev);
    }
};

int main(int argc, char **argv) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    inorderTravel(root);
    cout << endl << "---------" << endl;
    
    Solution sol;
    sol.recoverTree(root);
    
    inorderTravel(root);
    cout << endl;
    clearTree(root);
    
    return 0;
}
