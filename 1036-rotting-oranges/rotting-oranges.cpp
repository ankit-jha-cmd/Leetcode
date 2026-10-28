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
        int cnt=-1;
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,1,0,-1};
        while(!q.empty()){
            int len=q.size();
            while(len--){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m
                    && grid[nr][nc]==1 && !vis[nr][nc]){
                        q.push({nr, nc});
                        vis[nr][nc]=1;
                    }
                }
            }
            cnt++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1) return -1;
            }
        }
        return cnt==-1? 0: cnt;
    }
};