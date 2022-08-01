// BM52 数组中只出现一次的两个数字
// https://www.nowcoder.com/practice/389fc1c3d3be4479a154f63f495abff8?tpId=295&tqId=1375231&ru=%2Fpractice%2F253d2c59ec3e4bc68da16833f79a38e4&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj
// 核心：使用异或运算对所有元素进行异或操作，将重复的数据清理掉，然后再将仅出现一次的数据分离出来。
// 异或：位运算，相等为0，不等为1，所以相对数字异或为0. 0与任何数字异或为原数。
// 分离：使用1做&操作找到一个不相等的一位，然后用这一位辨别两个数。
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