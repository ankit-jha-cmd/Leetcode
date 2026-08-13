class Solution {
public:
int bfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>&vis){
    int n=grid.size();
    int m=grid[0].size();
    vis[row][col]=1;
    int maxsize=1;
    int size=1;
    queue<pair<int, int>>q;
    q.push({row, col});
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
        && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
            size++;
            maxsize=max(maxsize, size);
            vis[nrow][ncol]=1;
            q.push({nrow, ncol});
        }   
        }
    }
    return maxsize;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans=max(ans,bfs(grid, i, j, vis));
                }
            }
        }
        return ans;
    }
};