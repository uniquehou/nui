// BM35 判断是不是完全二叉树
#include <iostream>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    bool isCompleteTree(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q;
        TreeNode *t;
        q.push(root);

        while(!q.empty()) {
            t = q.front();
            q.pop();
            if (t) {
                q.push(t->left);
                q.push(t->right);
            } else {
                while(!q.empty()) {
                    if (q.front()!=nullptr)
                        return false;
                    q.pop();
                }
                break;
            }
        }
        return true;
    }
};