// BM38 在二叉树中找到两个节点的最近公共祖先
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr);
};

class Solution {
public:
    void dfs(TreeNode *t, int o1, int o2, vector<TreeNode*> &s1, vector<TreeNode*> &s2, int &flag1, int &flag2) {
        if (flag1 && flag2) return;
        if (!flag1) {
            flag1 = t->val == o1;
            s1.push_back(t);
        }
        if (!flag2) {
            flag2 = t->val == o2;
            s2.push_back(t);
        }
        dfs(t->left, o1, o2, s1, s2, flag1, flag2);
        if (!flag1) s1.pop_back();
        if (!flag2) s2.pop_back();
        dfs(t->right, o1, o2, s1, s2, flag1, flag2);
        if (!flag1) s1.pop_back();
        if (!flag2) s2.pop_back();
    }

    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        vector<TreeNode *> s1, s2;
        int flag1=0, flag2=0;   // o1, o2是否已找到
        dfs(root, o1, o2, s1, s2, flag1, flag2);
        for(int i=0; i<s1.size()-1; ++i)
            if (s1[i+1]->val!=s2[i+1]->val)
                return s1[i]->val;
    }
};