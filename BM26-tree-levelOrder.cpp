// BM26 求二叉树的层序遍历
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
     vector<vector<int> > levelOrder(TreeNode *root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int> > res;
        TreeNode *t = root;
        q.push(t);
        q.push(nullptr);
        res.push_back({});
        while(!q.empty()) {
            t = q.front();
            q.pop();
            if (t) {
                res.back().push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            } else {
                if (q.empty()) break;
                q.push(nullptr);
                res.push_back({});
            }
        }
        return res;
    }
};