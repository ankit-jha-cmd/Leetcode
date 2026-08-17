class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        vector<vector<int>>overlap;
        for(int i=0;i<intervals.size();i++){
            if(newInterval[1]>=intervals[i][0] && newInterval[0]<=intervals[i][1]){
                overlap.push_back(intervals[i]);
            }
            else ans.push_back(intervals[i]);
        }
        if(!overlap.empty()){
            newInterval[0]=min(newInterval[0], overlap[0][0]);
            newInterval[1]=max(newInterval[1], overlap.back()[1]);
        }
        ans.push_back(newInterval);
        sort(ans.begin(), ans.end());
        return ans;
    }
};