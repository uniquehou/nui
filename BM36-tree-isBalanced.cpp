// BM36 判断是不是平衡二叉树
#include <iostream>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    bool IsBalanced_Solution(TreeNode *pRoot) {
        if (!pRoot) return true;
        return abs(maxDepth(pRoot->left) - maxDepth(pRoot->right))<=1 &&
            IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
}