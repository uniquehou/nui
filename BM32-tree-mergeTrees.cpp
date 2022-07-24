// BM32 合并二叉树
#include <iostream>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1==nullptr)
            return t2;
        if (t2) {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
        }
        return t1;
    }
};