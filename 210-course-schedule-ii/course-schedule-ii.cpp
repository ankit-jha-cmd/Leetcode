class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>ans;
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][1];
            int b=prerequisites[i][0];
            adj[a].push_back(b);
            indegree[b]++;
        }
        queue<int>q;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
            if(i==indegree.size()-1 && q.empty()) return ans;
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans.size()==numCourses? ans : vector<int>{};
    }
};