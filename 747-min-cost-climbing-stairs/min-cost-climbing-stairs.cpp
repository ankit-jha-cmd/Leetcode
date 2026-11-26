class Solution {
public:
int minCost(vector<int>& nums, int ind, vector<int>&dp){
    if(ind>=nums.size()){
        return 0;
    }
    if(dp[ind]!=-1) return dp[ind];
    int takeOneStep=nums[ind]+ minCost(nums, ind+1, dp);
    int takeTwoSteps=nums[ind]+ minCost(nums, ind+2, dp);
    return dp[ind]=min(takeOneStep, takeTwoSteps);
}
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, -1);
        int startFromZero= minCost(cost, 0, dp);
        int startFromOne=  minCost(cost, 1, dp);
        return min(startFromZero, startFromOne);
    }
};