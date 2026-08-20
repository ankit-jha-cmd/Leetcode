class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        vector<int>ans;
        for(auto it: st){
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end());
        if(ans.size()<3) return ans[ans.size()-1];
        return ans[ans.size()-3];
    }
};