class Solution {
public:
bool check(vector<vector<int>>&adj, int node, vector<int>&vis, vector<int>&path){
      vis[node]=1;
      path[node]=1;
      for(auto it: adj[node]){
          if(!vis[it]){
              if(!check(adj, it, vis, path)) return false;
          }
          if(path[it]) return false;
          
      }
      path[node]=0;
      return true;
  }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(numCourses, 0);
        vector<int>path(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
             if(!check(adj, i, vis, path)) return false;   
            }
        }
        return true;
    }
};