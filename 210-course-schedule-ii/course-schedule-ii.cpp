class Solution {
public:
bool checkfn(int node, vector<int>&path, vector<int>& vis, vector<vector<int>>& adj, vector<int>& ans){
    vis[node]=1;
    path[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(!checkfn(it, path, vis, adj, ans)) return false;
        }
        if(path[it]) return false;
    }
    path[node]=0;
    ans.push_back(node);
    return true;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>vis(numCourses, 0);
        vector<int>path(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses; i++){
            if(!vis[i]){
                if(!checkfn(i, path, vis, adj, ans)) return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};