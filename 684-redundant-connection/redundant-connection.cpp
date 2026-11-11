class Solution {
class DSU{
    vector<int>parent, size;
    public:
    DSU(int n){
        parent.resize(n+1,1);
        size.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int findultparent(int a){
        if(parent[a]==a) return a;
        return parent[a]=findultparent(parent[a]);
    }

    bool unionfind(int a, int b){
        int ult_a=findultparent(a);
        int ult_b=findultparent(b);
        if(ult_a==ult_b) return true;
        if(size[ult_a]<size[ult_b]){
            size[ult_b]+=size[ult_a];
            parent[ult_a]=ult_b;
        }
        else{
            size[ult_a]+=size[ult_b];
            parent[ult_b]=ult_a;
        }
        return false;
    }
};
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU obj(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            if(obj.unionfind(a,b)) return {a,b};
        }
        return {};
    }
};