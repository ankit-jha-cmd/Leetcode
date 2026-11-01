class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int min=-1;
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        while(!q.empty()){
            int len=q.size();
            while(len--){
                auto[r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=r+drow[i];
                    int ncol=c+dcol[i];
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0
                    && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                        q.push({nrow, ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
            min++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return min==-1? 0: min;
    }
};