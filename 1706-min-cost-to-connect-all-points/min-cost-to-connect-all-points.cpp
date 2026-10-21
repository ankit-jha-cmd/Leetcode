class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int sum=0;
        vector<int>vis(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int node=pq.top()[1];
            int wt=pq.top()[0];
            pq.pop();
            if(vis[node]) continue;
            sum+=wt;
            vis[node]=1;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int x1=points[node][0];
                    int y1=points[node][1];

                    int x2=points[i][0];
                    int y2=points[i][1];

                    int cost= abs(x1-x2)+abs(y1-y2);
                    pq.push({cost, i});
                }
            }
        }
        return sum;
    }
};