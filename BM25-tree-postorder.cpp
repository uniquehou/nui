// BM25 二叉树的后序遍历
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr);
};

class Solution{
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode *t = root, *r=nullptr;

        while(!s.empty() || t) {
            while(t) {
                s.push(t);
                t = t->left;
            }
            t = s.top();
            if (t->right && t->right!=r) {
                t = t->right;
                continue;
            }
            res.push_back(t->val);
            r = t;
            s.pop();
            t = nullptr;
        }
        return res;
    }
};