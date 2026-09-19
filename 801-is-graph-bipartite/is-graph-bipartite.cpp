class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        vector<int>colored(graph.size(), -1);
        for(int i=0;i<graph.size();i++){
            if(colored[i]==-1){
                q.push(i);
                colored[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it: graph[node]){
                        if(colored[it]==-1){
                            colored[it]=!colored[node];
                            q.push(it);
                        }
                        else{
                            if(colored[it]==colored[node]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};