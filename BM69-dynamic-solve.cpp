// BM69 把数字翻译成字符串
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int solve(string nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if (nums[0]!='0') dp[0] = 1;
        if (nums)
        for(int i=2; i<n; i++) {
            if (nums[i-1]>='3' && nums[i]=='0')
                dp[i] = dp[i-1];
            else if (num[i-1]<'3' && nums[i]=='0')
                dp[i] = dp[i-2] + 1;
            if (nums[i]<='6' && nums[i-1]>'0' && nums[i-1]<='2')
                dp[i]++;
            else if (nums[i-1]=='1')
                dp[i]++;
        }
        return dp[n-1];
    }
};