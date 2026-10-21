class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<int>vis(n, 0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int val=0;
        pq.push({0,0});
        while(!pq.empty()){
            int wt=pq.top()[0];
            int node=pq.top()[1];
            pq.pop();
            if(vis[node]) continue;
            val+=wt;
            vis[node]=1;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                int x1=points[node][0];
                int y1=points[node][1];

                int x2=points[i][0];
                int y2=points[i][1];

                int cost= abs(x1-x2)+abs(y1-y2);
                pq.push({cost, i});
            }
            
        }
        return val;
    }
};