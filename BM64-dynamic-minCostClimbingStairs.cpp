// BM64 最小花费爬楼梯
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        if (n==1) return cost[0];
        vector<int> dp(n+1, 0);
        for(int i=2; i<=n; i++)
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        return dp[n];
    }
};