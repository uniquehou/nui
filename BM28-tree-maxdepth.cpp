// BM28 二叉树的最大深度
#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root)
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        else
            return 0;
    }
};