class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    
    int dfs(vector<vector<int>>& grid,
            vector<vector<int>>& vis,
            int i, int j) {
        
        vis[i][j] = 1;
        int area = 1;   // count current cell
        
        for(auto &p : dir) {
            int a = i + p[0];
            int b = j + p[1];
            
            if(a >= 0 && b >= 0 &&
               a < n && b < m &&
               grid[a][b] == 1 &&
               !vis[a][b]) {
                
                area += dfs(grid, vis, a, b);
            }
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1 && !vis[i][j]) {
                    int temp = dfs(grid, vis, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        
        return ans;
    }
};