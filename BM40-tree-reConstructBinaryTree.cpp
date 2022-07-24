// BM40 重建二叉树
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty()) return nullptr;
        TreeNode *node = new TreeNode(pre[0]);

        int mid;
        for(mid=0; vin[mid]!=pre[0]; ++mid);
        node->left = reConstructBinaryTree(vector<int>(pre.begin()+1, pre.begin()+mid+1), vector<int>(vin.begin(), vin.begin()+mid));
        node->right = reConstructBinaryTree(vector<int>(pre.begin()+mid+1, pre.end()), vector<int>(vin.begin()+mid+1, vin.end()));
        return node;
    }
};