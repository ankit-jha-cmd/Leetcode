class Solution {
public:
void dfs(int node, vector<vector<int>>& adjMatrix, vector<int>& vis){
    vis[node]=1;
    for(int i=0;i<adjMatrix.size();i++){
        if(!vis[i] && adjMatrix[node][i]==1){
            dfs(i, adjMatrix, vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n, 0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                cnt++;
            }
        }
        return cnt;
    }
};