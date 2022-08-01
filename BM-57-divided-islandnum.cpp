// BM57 岛屿数量
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i<0 || i>=m || j<0 || j>=n)
            return;
        if (grid[i][j]=='1') {
            grid[i][j] = '2';
            dfs(grid, i, j+1);
            dfs(grid, i, j-1);
            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
        }
    }

    int solve(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        int res = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if (grid[i][j]=='1') {
                    dfs(grid, i, j);
                    res++;
                }
        return res;
    }
}