class Solution {
public:
void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, queue<pair<int, int>>&q, int n, int m){
        vector<int>delr={-1,0,1,0};
        vector<int>delc={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col= q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delr[i];
                int ncol=col+delc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&
                grid[nrow][ncol]!='0'){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int, int>>q;
        int cnt=0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j]=1;
                    bfs(grid, vis, q, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};