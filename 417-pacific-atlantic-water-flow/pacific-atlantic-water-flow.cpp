class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n= heights.size();
        int m=heights[0].size();
        queue<pair<int, int>>pacific;
        queue<pair<int, int>>atlantic;
        vector<vector<int>>p(n, vector<int>(m, 0));
        vector<vector<int>>a(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            pacific.push({i,0});
            p[i][0]=1;
        }

        for(int j=0;j<m;j++){
            pacific.push({0,j});
            p[0][j]=1;
        }

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pacific.empty()){
            auto [r,c]=pacific.front();
            pacific.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && !p[nrow][ncol] && heights[nrow][ncol]>=heights[r][c]){
                    pacific.push({nrow, ncol});
                    p[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            atlantic.push({i, m-1});
            a[i][m-1]=1;
        }
        for(int j=0;j<m;j++){
            atlantic.push({n-1, j});
            a[n-1][j]=1;
        }

        while(!atlantic.empty()){
            auto [r,c]=atlantic.front();
            atlantic.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && !a[nrow][ncol] && heights[nrow][ncol]>=heights[r][c]){
                    atlantic.push({nrow, ncol});
                    a[nrow][ncol]=1;
                }
            }
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] && p[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};