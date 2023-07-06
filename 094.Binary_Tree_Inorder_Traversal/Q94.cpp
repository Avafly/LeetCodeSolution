#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insert(TreeNode* root, int val) {
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

void freeTree(TreeNode *root) {
    if(root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        rec(root, ans);
        return ans;
    }
private:
    void rec(TreeNode *node, vector<int> &ans) {
        if (node == nullptr) {
            return;
        }
        rec(node->left, ans);
        ans.push_back(node->val);
        rec(node->right, ans);
    }
};

int main() {
    vector<int> arr = {2,3,4,5,7,8,9};
    TreeNode *root = nullptr;
    // create tree
    for(int val : arr) {
        root = insert(root, val);
    }

    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);
    for(int n : ans) {
        cout << n << " ";
    }
    cout << endl;

    /* free the memory */
    freeTree(root);

    return 0;
}
