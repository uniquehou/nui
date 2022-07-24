// BM34 判断是不是二叉搜索树
#include <iostream>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *t = root, *pre=nullptr;

        while(!s.empty() || t) {
            while(t) {
                s.push(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            if (pre && pre->val > t->val)
                return false;
            pre = t;
            t = t->right;
        }
        return true;
    }
};