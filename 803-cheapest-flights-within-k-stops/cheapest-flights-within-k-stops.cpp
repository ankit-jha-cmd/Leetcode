class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n, INT_MAX);
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int a=flights[i][0];
            int b=flights[i][1];
            int wt=flights[i][2];
            adj[a].push_back({wt,b});
        }
        queue<vector<int>>q;
        q.push({src, 0, 0});
        dist[src]=0;
        while(!q.empty()){
            int node= q.front()[0];
            int wt=q.front()[1];
            int stops=q.front()[2];
            if(stops>k) break;
            q.pop();
            for(auto it: adj[node]){
                int nbr=it.second;
                int cost=it.first;
                if(wt+cost<dist[nbr]){
                    dist[nbr]=wt+cost;
                    q.push({nbr, wt+cost, stops+1});
                }
            }
        }
        return dist[dst]==INT_MAX? -1: dist[dst];
    }
};