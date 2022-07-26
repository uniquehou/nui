// BM23 二叉树的前序遍历
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<struct TreeNode*> s;
        vector<int> res;

        TreeNode *t = root;
        while(!s.empty() || t) {
            while(t) {
                res.push_back(t->val);
                s.push(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            t = t->right;
        }
        return res;
    }
};