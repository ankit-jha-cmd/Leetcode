class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int cnt=1;
        vector<int>ans;
        while(cnt<=nums.size()){
            if(mpp.find(cnt)==mpp.end()){
                ans.push_back(cnt);
            }
            cnt++;
        }
        return ans;
    }
};