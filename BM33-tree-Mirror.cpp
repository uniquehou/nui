// BM33 二叉树的镜像
#include <iostream>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if (pRoot) {
            TreeNode *t;
            t = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = t;
            Mirror(pRoot->right);
            Mirror(pRoot->left);
        }
        return pRoot;
    }
};