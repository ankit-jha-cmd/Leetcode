class Solution {
public:
void dfs(int node, int parent, vector<vector<int>>&adj, int& timer, vector<int>&vis, vector<int>&disc, vector<int>& ld, vector<vector<int>>&res){
    vis[node]=1;
    disc[node]=timer;
    ld[node]=timer;
    timer++;
    for(auto it: adj[node]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs(it, node, adj, timer, vis, disc, ld, res);
            // when backtracking update the ld[node] comparing with its child node.
            ld[node]=min(ld[node], ld[it]); 
            if(ld[it]>disc[node]) res.push_back({node, it});
        }
        else{
            //if the adj node we checking is already visited but not the parent.
            ld[node]=min(ld[node], disc[it]);
        }
    }

}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int timer=1;
        vector<int>disc(n,-1);
        vector<int>lowdisc(n,-1);
        
        vector<int>vis(n,0);
        vector<vector<int>>res;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, -1, adj, timer, vis, disc, lowdisc, res);
            }
        }
        return res;
    }
};