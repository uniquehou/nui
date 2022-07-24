// BM24 二叉树的中序遍历
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* t = root;

        while(!s.empty() || t) {
            while(t) {
                s.push(t);
                t = t->left;
            }
            t = s.top();
            res.push_back(t->val);
            s.pop();
            t = t->right;
        }
        return res;
    }
};