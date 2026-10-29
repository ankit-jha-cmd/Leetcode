class Solution {
public:
int fn(int ind, vector<int>& nums, vector<int>& dp){
    if(ind>=nums.size()) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int rob=  nums[ind]+fn(ind+2, nums, dp);
    int skip= fn(ind+1, nums, dp);
    return dp[ind]=max(rob, skip);
}
    int rob(vector<int>& nums) {
        int maxtheft=0;
        vector<int>dp(nums.size(),-1);
        return fn(0, nums, dp);
    }
};