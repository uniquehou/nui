// BM41 输出二叉树的右视图
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void dfs(vector<int> pre, vector<int> vin, int level, vector<int> &res) {
        if (pre.empty()) return;
        TreeNode *node = new TreeNode(pre[0]);
        if (res.size()==level)
            res.push_back(pre[0]);
        else
            res[level] = pre[0];

        int mid;
        for(mid=0; vin[mid]!=pre[0]; ++mid);
        dfs(vector<int>(pre.begin()+1, pre.begin()+mid+1), vector<int>(vin.begin(), vin.begin()+mid), level+1, res);
        dfs(vector<int>(pre.begin()+mid+1, pre.end()), vector<int>(vin.begin()+mid+1, vin.end()), level+1, res);
    }

    vector<int> solve(vector<int> &pre, vector<int> &vin) {
        vector<int> res;
        dfs(pre, vin, 0, res);
        return res;
    }
};