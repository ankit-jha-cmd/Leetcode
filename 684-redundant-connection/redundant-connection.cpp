class Solution {
    class DSU{
        public:
        vector<int>size, parent;
        DSU(int n){
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i=1;i<=n;i++) parent[i]=i;
        }
        int findUltParent(int x){
            if(parent[x]==x) return x;
            return parent[x]=findUltParent(parent[x]);
        }

        bool unionbysize(int u, int v){
            int ultP_u=findUltParent(u);
            int ultP_v=findUltParent(v);
            if(ultP_u == ultP_v) return true;
            if(size[ultP_u] < size[ultP_v]){
                parent[ultP_u]= ultP_v;
                size[ultP_v]+=size[ultP_u];
            }
            else {
                parent[ultP_v]= ultP_u;
                size[ultP_u]+=size[ultP_v];
            }
            return false;
        }
    };
    public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n=edges.size();
       DSU obj(n);
       for(auto it: edges){
        int i=it[0];
        int j=it[1];
        if(obj.unionbysize(i,j)) return {i,j};
       }
        return {};
    }
};
