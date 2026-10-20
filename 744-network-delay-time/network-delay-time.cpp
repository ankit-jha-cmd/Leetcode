class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int a=times[i][0];
            int b=times[i][1];
            int w=times[i][2];
            adj[a].push_back({b,w});
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>dist(n+1, INT_MAX);
        dist[k]=0;
        pq.push({0, k});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                if(d+ it.second < dist[it.first]){
                    dist[it.first]=d+it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        int maxdist=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            maxdist=max(maxdist, dist[i]);
        }
        return maxdist;
    }
};