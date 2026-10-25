class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n, vector<int>(n,INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        while(!pq.empty()){
            int d=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];
            pq.pop();
            if(r==n-1 && c==n-1) return d;
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                    int newdist= max(d,grid[nrow][ncol]); //get maximum d or t
                    if(newdist<dist[nrow][ncol]){  //in smalles path that we pick.
                        dist[nrow][ncol]=newdist;
                        pq.push({newdist, nrow, ncol});
                    }
                }
            }
        }
        return -1;
    }
};