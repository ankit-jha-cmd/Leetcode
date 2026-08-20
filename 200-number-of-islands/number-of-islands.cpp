class Solution {
public:
    void bfs(vector<vector<char>>& grid, int r, int c, int n, int m, 
    vector<vector<int>>& vis){
        vis[r][c]=1;
        queue<pair<int, int>>q;
        q.push({r,c});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delr[i];
                int ncol=col+delc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }   
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(grid, i, j, n, m, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};