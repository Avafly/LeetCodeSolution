
// LeetCode Problem:
// Title: Validate Binary Search Tree
// URL: https://leetcode.com/problems/validate-binary-search-tree/

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
    cout << root->val << endl;
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
    bool isValidBST(TreeNode *root) {
        return isValid(root, nullptr, nullptr);
    }
    
private:
    bool isValid(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if(root == nullptr) {
            return true;
        }
        if(minNode != nullptr && root->val <= minNode->val) {
            return false;
        }
        if(maxNode != nullptr && root->val >= maxNode->val) {
            return false;
        }
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
};

int main(int argc, char **argv) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    //inorderTravel(root);
    
    Solution sol;
    cout << (sol.isValidBST(root) ? "True" : "False") << endl;;
    
    clearTree(root);
    
    return 0;
}
