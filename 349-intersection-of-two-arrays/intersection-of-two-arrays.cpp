class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        vector<int>ans;
        unordered_set<int>st;
        for(int i=0;i<nums2.size();i++){
            if(mp.find(nums2[i])!=mp.end()) st.insert(nums2[i]);
        }
        for(auto it: st) ans.push_back(it);
        return ans;
    }
};