// BM37 二叉搜索树的最近公共祖先
#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int lowestCommonAncestor(TreeNode *t, int p, int q) {
        if (!t) return -1;
        if (p==t->val || q==t->val || p<t->val && q>t->val || p>t->val && q<t->val)
            return t->val;
        int m = lowestCommonAncestor(t->left, p, q);
        if (m<0)
            m = lowestCommonAncestor(t->right, p, q);
        return m;
    }
};