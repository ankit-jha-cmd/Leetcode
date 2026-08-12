class Solution {
public:
void dfs(vector<vector<int>>& adjmatrix, int node, vector<int>& vis){
    vis[node]=1;
    for(int j=0;j<adjmatrix.size();j++){
        if(adjmatrix[node][j]==1 && !vis[j]){
            dfs(adjmatrix, j, vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>vis(isConnected.size(), 0);
        int cnt=0;
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                dfs(isConnected, i, vis);
                cnt++;
            } 
        }
        return cnt;
    }
};