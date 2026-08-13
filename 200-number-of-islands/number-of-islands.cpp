class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, int n, int m, vector<vector<int>>&vis){
        vis[row][col]=1;
        queue<pair<int, int>>q;
        q.push({row, col});
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,1,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                    && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow, ncol});
                }
            }
        }
    }   

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1' && !vis[row][col]){
                    bfs(row, col, grid, n, m, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};