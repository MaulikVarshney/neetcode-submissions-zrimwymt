class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    freshOranges++;
                } else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        if(freshOranges == 0) return 0;
        int days = 0;
        int rt = 0;
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int s = q.size();
            
            for(int i=0;i<s;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int dx = x+dir[i][0];
                    int dy = y+dir[i][1];
                    if(dx<0 || dy<0 || dx>=n || dy>=m || grid[dx][dy]!=1) continue;
                    grid[dx][dy] = 2;
                    rt++;
                    q.push({dx,dy});
                }
            }
            if(q.size()!=0)days++;
        }
        return rt == freshOranges ? days : -1;
    }
};
