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

TreeNode *insertNode(TreeNode *root, int &val) {
    if(root == nullptr) {
        return new TreeNode(val);
    }
    if(val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int getHeight(TreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

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
        return rec(1, n);
    }
private:
    vector<TreeNode *> rec(int start, int end) {
        vector<TreeNode *> ans;
        if(start > end) {
            ans.push_back(nullptr);
            return ans;
        }

        for(int i = start; i <= end; ++i) {
            vector<TreeNode *> leftTrees = rec(start, i - 1);
            vector<TreeNode *> rightTrees = rec(i + 1, end);

            // add an unique tree
            for(int p = 0; p < leftTrees.size(); ++p) {
                for(int q = 0; q < rightTrees.size(); ++q) {
                    TreeNode *root = new TreeNode(i);
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
    int n = 4;
    Solution sol;
    vector<TreeNode *> ans = sol.generateTrees(n);
    cout << ans.size() << endl;
    for(TreeNode *root : ans) {
        printTree(root);
        cout << "----------" << endl;
    }
//    for(TreeNode *root : ans) {
//        clearTree(root);
//    }
    
    return 0;
}
