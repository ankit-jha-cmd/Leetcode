class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][1];
            int b=prerequisites[i][0];
            adj[a].push_back(b);
            indegree[b]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
            if(i==n-1 && q.empty()) return false;
        }

        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans.size()==n? true: false;
    }
};