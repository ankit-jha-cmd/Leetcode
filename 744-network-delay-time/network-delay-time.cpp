class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1, INT_MAX);
        dist[k]=0;
        for(int i=0;i<n;i++){
            for(int i=0;i<times.size();i++){
                if(dist[times[i][0]]==INT_MAX) continue;
                else if(dist[times[i][0]]+times[i][2]<dist[times[i][1]]){
                    dist[times[i][1]]=dist[times[i][0]]+times[i][2];
                }
            }
        }
        int maxdist=-1;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            maxdist=max(maxdist, dist[i]);
        }
        return maxdist;
    }
};