// BM29 二叉树中和为某一值的路径(一)
#include <iostream>
#include <vector>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==nullptr) return false;
        if (root->left==nullptr && root->right==nullptr && root->val==sum)
            return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
}