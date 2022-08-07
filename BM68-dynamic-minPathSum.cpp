// BM68 矩阵的最小路径和
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(matrix.begin(), matrix.end());
        for(int i=1; i<m; i++)
            dp[i][0] += dp[i-1][0];
        for(int j=1; j<n; j++)
            dp[0][j] += dp[0][j-1];
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
        return dp[m-1][n-1];
    }
};