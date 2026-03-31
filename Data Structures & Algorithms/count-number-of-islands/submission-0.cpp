class Solution {
    int n,m;
    vector<vector<int>> li = {{1,0},{0,1},{0,-1}, {-1,0}};
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis ,int i, int j){
        vis[i][j] = 1;
        for(auto p: li){
            int a = i + p[0];
            int b = j + p[1];
            if(a >= 0 && b >= 0 && a < n && b < m && grid[a][b] == '1' && vis[a][b] != 1){
                dfs(grid,vis,a,b);
            }
        }
    }
public:
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};
