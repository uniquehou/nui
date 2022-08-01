// BM56 有重复项数字的全排列
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void perm(vector<vector<int>> &res, vector<int> &num, int k, int m) {
        if (k==m)
            res.push_back(num);
        else
            for(int i=0; i<=m; i++) {
                if (num[i]==num[i+1])
                    continue;
                swap(num[i], num[k]);
                perm(res, num, k+1, m);
                swap(num[i], num[k]);
            }
    }
    
    vector<vector<int>> permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        perm(res, num, 0, num.size()-1);
    }
};