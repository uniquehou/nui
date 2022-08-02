// BM63 跳台阶
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp(number, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<number; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[number-1];
    }
};