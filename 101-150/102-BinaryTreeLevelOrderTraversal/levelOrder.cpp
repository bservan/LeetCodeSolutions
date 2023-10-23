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

/*
 * To test this code locally, I also provide TreeNode struct right below:
 */

#include <vector>

using std::size_t;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<vector<int>> levels;

    void addElement(size_t level, int num) {
        if (level >= levels.size()) {
            levels.resize(level + 1);
        }
        levels[level].push_back(num);
    }

    void traverseTree(size_t level, const TreeNode *root) {
        if (root->left) {
            addElement(level, root->left->val);
            traverseTree(level + 1, root->left);
        }
        if (root->right) {
            addElement(level, root->right->val);
            traverseTree(level + 1, root->right);
        }
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        size_t level {};

        if (root) {
            addElement(level++, root->val);
            traverseTree(level, root);
        }

        return levels;
    }
};
