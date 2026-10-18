class Solution {
public:
int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, queue<pair<int,int>>q){
    int area=0;
    q.push({row, col});
    vis[row][col]=1;
    area++;
    vector<int>drow={-1,0,1,0};
    vector<int>dcol={0,1,0,-1};
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() &&
            !vis[nrow][ncol] && grid[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                q.push({nrow, ncol});
                area++;
            }
        }
    }
    return area;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    maxarea=max(maxarea, bfs(grid, vis, i,j, q));
                }
            }
        }
        return maxarea;
    }
};