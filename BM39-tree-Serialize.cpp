// BM39 序列化二叉树
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

using namespace std;
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    char* Serialize(TreeNode *root) {
        string s;
        queue<TreeNode*> q;
        TreeNode *t;
        if (!root)
            q.push(root);
        while(!q.empty()) {
            t = q.front();
            q.pop();
            if (t) {
                s += to_string(t->val);
                q.push(t->left);
                q.push(t->right);
            } else {
                s += "#";
            }
            s += ",";
        }
        char *c = new char[s.size()+1];
        strcpy(c, s.c_str());
        return c;
    }

    TreeNode *Deserialize(char *str) {
        string s(str);
        int index=0;
        vector<TreeNode*> tree;
        while(index<s.size()) {
            int sep = s.find_first_of(",", index);
            TreeNode *t;
            if (s[sep]=='#') {
                t = nullptr;
            } else {
                int val = stoi(s.substr(index, sep));
                TreeNode *t = new TreeNode(val);
            }
            
            tree.push_back(t);
            int num = tree.size();
            if (num>1)    // num=0，此结点为根结点
                if (num%2==0)    // 偶数节点，父结点左孩子
                    tree[num/2-1]->left = t;
                else             // 奇数节点，父结点右孩子
                    tree[num/2-1]->right = t;

            index = sep + 1;

        }
        return tree[0];
    }
};