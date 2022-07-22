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
        s.push(root);
        while(!s.empty()) {
            TreeNode *t = s.top();
            while(t) {
                res.push_back(t->val);
                t = t->left;
            }
        }
    }
};