class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=intervals.size();
        int m=queries.size();
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>>sortedq;
        for(int i=0;i<m;i++){
            sortedq.push_back({queries[i], i});
        }
        sort(sortedq.begin(), sortedq.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>ans(m, -1);
        int i=0;
        for(int j=0;j<m;j++){
            int q=sortedq[j].first;
            int ind=sortedq[j].second;
            while(i<n && intervals[i][0]<=q){
                int size=  intervals[i][1]-intervals[i][0]+1;
                pq.push({size, intervals[i][1]});
                i++;
            }
            while(!pq.empty() && pq.top().second<q){
                pq.pop();
            }
            if(!pq.empty()) ans[ind]=pq.top().first;
        }
        return ans;
    }
};