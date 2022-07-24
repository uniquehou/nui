// BM30 二叉搜索树与双向链表
#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    void inorder(TreeNode *root, TreeNode *&pre, TreeNode *&head) {
        if (root) {
            inorder(root->left, pre, head);
            root->left = pre;
            if (pre)
                pre->right = root;
            else
                head = head? head: root;
            pre = root;
            inorder(root->right, pre, head);
        }
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode *head = nullptr, *pre = nullptr;
        inorder(pRootOfTree, pre, head);
        if (pre)
            pre->right = nullptr;
        return head;
    }
};