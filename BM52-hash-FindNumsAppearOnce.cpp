// BM52 数组中只出现一次的两个数字
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        vector<int> res(2, 0);
        int temp = 0;
        //遍历数组得到a^b
        for(int i = 0; i < array.size(); i++)
            temp ^= array[i];
        int k = 1;
        //找到两个数不相同的第一位
        while((k & temp) == 0)
            k <<= 1;
        for(int i = 0; i < array.size(); i++){
            //遍历数组，对每个数分类
            if((k & array[i]) == 0)
                res[0] ^= array[i];
            else
                res[1] ^= array[i];
        }
        //整理次序
        if(res[0] < res[1])
            return res;
        else
            return {res[1], res[0]};
    }
};