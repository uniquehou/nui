// BM51 数组中出现次数超过一半的数字
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int res = numbers[0], count = 1;
        for(int i=1; i<numbers.size(); i++) {
            if (count>0)
                if (res = numbers[i]) count++;
                else count--;
            else {
                res = numbers[i];
                count = 1;
            }
        }
        return res;
    }
}