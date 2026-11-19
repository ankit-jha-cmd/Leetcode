class Solution {
public:
void dfs(int node, int parent, int &cnt, vector<vector<vector<int>>>&adj){
    for(auto it: adj[node]){
        int v=it[0];
        if(v!=parent){
            int check=it[1];
            if(check==1) cnt+=1;
            dfs(v, node, cnt, adj);
        }
    }
}
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<vector<int>>>adj(n);
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }
        int cnt=0;
        dfs(0, -1, cnt, adj);
        return cnt;
    }
};