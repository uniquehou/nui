// BM67 不同路径的数目(一)
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int uniquePaths(int m, int n) {
        if (m==0 || n==0) return 0;
        if (m==1 || n==1) return 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};

int main() {
    Solution ss;
    cout << ss.uniquePaths(2, 2) << endl;
}