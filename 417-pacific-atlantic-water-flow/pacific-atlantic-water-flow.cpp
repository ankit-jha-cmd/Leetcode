class Solution {
public:
void traversePacific(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& vis){
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        q.push({i,0});
        vis[i][0]=1;
    }
    for(int i=0;i<m;i++){
        q.push({0,i});
        vis[0][i]=1;
    }

    vector<int>drow={-1,0,1,0};
    vector<int>dcol={0,1,0,-1};    
    while(!q.empty()){
        auto[row, col]= q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nrow= row+drow[i];
            int ncol= col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0  && ncol<m
            && grid[nrow][ncol]>=grid[row][col] && !vis[nrow][ncol]){
                q.push({nrow, ncol});
                vis[nrow][ncol]=1;
            }
        }
    }
}

void traverseAtlantic(vector<vector<int>>& grid, int n, int m, vector<vector<int>>& vis){
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        q.push({i,m-1});
        vis[i][m-1]=1;
    }
    for(int i=0;i<m;i++){
        q.push({n-1,i});
        vis[n-1][i]=1;
    }

    vector<int>drow={-1,0,1,0};
    vector<int>dcol={0,1,0,-1};    
    while(!q.empty()){
        auto[row, col]= q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nrow= row+drow[i];
            int ncol= col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0  && ncol<m
            && grid[nrow][ncol]>=grid[row][col] && !vis[nrow][ncol]){
                q.push({nrow, ncol});
                vis[nrow][ncol]=1;
            }
        }
    }
}

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pvis(n, vector<int>(m, 0));
        traversePacific(heights, n, m, pvis);
        vector<vector<int>>avis(n, vector<int>(m, 0));
        traverseAtlantic(heights, n, m, avis);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pvis[i][j] && avis[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};