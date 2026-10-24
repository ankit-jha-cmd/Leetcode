class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pvis(n, vector<int>(m,0));
        vector<vector<int>>avis(n, vector<int>(m,0));
        queue<pair<int, int>>pq;
        queue<pair<int, int>>aq;
        for(int i=0;i<n;i++){
            pq.push({i,0});
            pvis[i][0]=1;
            aq.push({i, m-1});
            avis[i][m-1]=1;
        }
        for(int j=0;j<m;j++){
            pq.push({0,j});
            pvis[0][j]=1;
            aq.push({n-1,j});
            avis[n-1][j]=1;
        }

        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        while(!pq.empty()){
            auto[r,c]=pq.front();
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                !pvis[nrow][ncol] && heights[nrow][ncol]>=heights[r][c]){
                    pq.push({nrow,ncol});
                    pvis[nrow][ncol]=1;
                }
            }
        }
        while(!aq.empty()){
            auto[r,c]=aq.front();
            aq.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                !avis[nrow][ncol] && heights[nrow][ncol]>=heights[r][c]){
                    aq.push({nrow,ncol});
                    avis[nrow][ncol]=1;
                }
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(avis[i][j] && pvis[i][j]){
                ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};