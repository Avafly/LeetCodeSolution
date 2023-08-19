#include <iostream>
#include <vector>
#include <queue>
#include <memory>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct sTreeNode {
    int val;
    shared_ptr<sTreeNode> left;
    shared_ptr<sTreeNode> right;
    sTreeNode() : val(0), left(nullptr), right(nullptr) {}
    sTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    sTreeNode(int x, shared_ptr<sTreeNode> left, shared_ptr<sTreeNode> right) : val(x), left(left), right(right) {}
};

void printTree(TreeNode *root) {
    if(root == nullptr) return;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()) {
        int levelSize = static_cast<int>(q.size());
        for(int i = 0; i < levelSize; ++i) {
            TreeNode *currNode = q.front();
            q.pop();
            if(currNode == nullptr) {
                cout << "null ";
            }
            else {
                cout << currNode->val << " ";
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        cout << endl;
    }
}

void clearTree(TreeNode *root) {
    if(root == nullptr) {
        return;
    }
    clearTree(root->left);
    clearTree(root->right);
    delete root;
    root = nullptr;
}

TreeNode *copyTree(const shared_ptr<sTreeNode> &root) {
    if (!root) {
        return nullptr;
    }
    TreeNode *node = new TreeNode(root->val);
    node->left = copyTree(root->left);
    node->right = copyTree(root->right);
    return node;
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
    vector<TreeNode*> generateTrees(int n) {
        return rec(n);
    }

private:
    vector<TreeNode *> rec(int n) {
        vector<shared_ptr<sTreeNode>> sans = srec(1, n);
        vector<TreeNode*> ans;
        // copy tree
        for(auto &tree : sans) {
            ans.push_back(copyTree(tree));
        }

        return ans;
    }

    vector<shared_ptr<sTreeNode>> srec(int start, int end) {
        vector<shared_ptr<sTreeNode>> ans;
        if(start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        for(int i = start; i <= end; ++i) {
            vector<shared_ptr<sTreeNode>> leftTrees = srec(start, i - 1);
            vector<shared_ptr<sTreeNode>> rightTrees = srec(i + 1, end);

            // add an unique tree
            for(int p = 0; p < leftTrees.size(); ++p) {
                for(int q = 0; q < rightTrees.size(); ++q) {
                    shared_ptr<sTreeNode> root = make_shared<sTreeNode>(i);
                    root->left = leftTrees[p];
                    root->right = rightTrees[q];
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    int n = 8;
    Solution sol;
    vector<TreeNode *> ans = sol.generateTrees(n);
    cout << ans.size() << endl;
    // print tree
//    for(TreeNode *root : ans) {
//        printTree(root);
//        cout << "----------" << endl;
//    }
    
    // clear memory
    for(TreeNode *root : ans) {
        clearTree(root);
    }
    
    return 0;
}
