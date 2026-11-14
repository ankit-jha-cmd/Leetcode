class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>overlapping;
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            if(!(newInterval[1]<intervals[i][0] || intervals[i][1]<newInterval[0])){
                overlapping.push_back(intervals[i]);
            }
            else ans.push_back(intervals[i]);
        }
        if(!overlapping.empty()){
            newInterval[0]=min(newInterval[0], overlapping[0][0]);
            newInterval[1]=max(newInterval[1], overlapping.back()[1]);
        }
        ans.push_back(newInterval);
        sort(ans.begin(), ans.end());
        return ans;
    }
};