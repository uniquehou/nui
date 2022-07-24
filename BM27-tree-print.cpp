// BM27 按之字形顺序打印二叉树
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
     vector<vector<int> > levelOrder(TreeNode *pRoot) {
        if (!pRoot) return {};
        queue<TreeNode*> q;
        vector<vector<int> > res;
        TreeNode *t = pRoot;
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
                if (res.size()%2==0)
                    reverse(res.back().begin(), res.back().end());
                if (q.empty()) break;
                q.push(nullptr);
                res.push_back({});
            }
        }
        return res;
    }
};