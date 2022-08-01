// BM55 没有重复项数字的全排列
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:
    void perm(vector<vector<int>> &res, vector<int> &num, int k, int m) {
        if (k==m)
            res.push_back(num);
        else
            for(int i=k; i<=m; i++) {
                swap(num[i], num[k]);
                perm(res, num, k+1, m);
                swap(num[i], num[k]);
            }   
    }
    
    vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> res;
        perm(res, num, 0, num.size()-1);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a{1,2,3};
    s.permute(a);
}