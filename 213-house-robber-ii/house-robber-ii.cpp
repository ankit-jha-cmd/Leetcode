class Solution {
public:
int fn2(vector<int>&nums, int n, vector<int>&dp){
    if(n==1) return nums[1];
    if(n<1) return 0;
    if(dp[n]!=-1) return dp[n];
    int pick=nums[n] + fn2(nums, n-2, dp);
    int notpick= fn2(nums, n-1, dp);
    return dp[n]=max(pick, notpick);
}

int fn(vector<int>&nums, int n, vector<int>&dp){
    if(n==0) return nums[0];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int pick=nums[n] + fn(nums, n-2, dp);
    int notpick= fn(nums, n-1, dp);
    return dp[n]=max(pick, notpick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n, -1);
        if(n==1) return nums[0];
        int withfirsthouse= fn(nums, n-2, dp);
        for(int i=0;i<n;i++) dp[i]=-1;
        int withlasthouse= fn2(nums, n-1, dp);
        return max(withfirsthouse, withlasthouse);
    }
};