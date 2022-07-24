// BM31 对称的二叉树
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
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot==nullptr)
            return true;
        stack<TreeNode*> s1, s2;
        TreeNode* t1 = pRoot->left, *t2 = pRoot->right;
        while( (!s1.empty() || t1) || (!s2.empty() || t2)) {
            while(t1 || t2) {
                if (!t1 && t2 || !t2 && t1)
                    return false;
                if (t1->val!=t2->val)
                    return false;
                s1.push(t1);
                s2.push(t2);
                t1 = t1->left;
                t2 = t2->right;
            }
            t1 = s1.top();
            s1.pop();
            t1 = t1->right;

            t2 = s2.top();
            s2.pop();
            t2 = t2->left;
        }
        return true;
    }
};