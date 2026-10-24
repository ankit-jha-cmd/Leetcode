class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int min=0;
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        while(!q.empty()){
            int len=q.size();
            while(len--){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+drow[i];
                    int nc=c+dcol[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m
                    && !vis[nr][nc] && grid[nr][nc]==1){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
            min++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1) return -1;
            }
        }
        return min==0? 0: min-1;
    }
};