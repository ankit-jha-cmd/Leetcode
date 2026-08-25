class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0) board[i][j]='X';
            }
        }
    }
};