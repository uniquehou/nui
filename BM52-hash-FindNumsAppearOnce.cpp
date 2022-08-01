// BM52 数组中只出现一次的两个数字
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        vector<int>res(2, 0);
        int tmp = 0;
        for(int i=0; i<array.size(); i++) {
            tmp ^= array[i];
        }
        int k = 1;
        while((k & tmp)==0)
            k <<= 1;
        for(int i=0; i<array.size(); i++) {
            if ((k & array[i])==0)
                res[0] ^= array[i];
            else
                res[1] ^= array[i];
        }
        sort(res.begin(), res.end());
        return res;
    }
};