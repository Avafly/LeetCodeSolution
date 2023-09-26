
// LeetCode Problem:
// Title: Same Tree
// URL: https://leetcode.com/problems/same-tree/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void clearTree(TreeNode *root) {
    if(root == nullptr) {
        return;
    }
    clearTree(root->left);
    clearTree(root->right);
    delete root;
    root = nullptr;
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == nullptr || q == nullptr) {
            return p == nullptr && q == nullptr;
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char **argv) {
    // create p
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    // create q
    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    
    Solution sol;
    bool ans = sol.isSameTree(p, q);
    cout << (ans == true ? "True" : "False") << endl;
    
    /* free the memory */
    clearTree(p);
    clearTree(q);
    return 0;
}
