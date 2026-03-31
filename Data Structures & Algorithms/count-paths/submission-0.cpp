class Solution {

    int dfs(int i, int j, vector<vector<int>>& dp, int m, int n){

        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = dfs(i+1, j, dp, m, n)
                        + dfs(i, j+1, dp, m, n);
    }

public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(0, 0, dp, m, n);
    }
};