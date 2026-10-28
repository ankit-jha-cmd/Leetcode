class Solution {
public:
int fn(int ind, vector<int>&cost, vector<int>&dp){
    if(ind>=cost.size()) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int option1= fn(ind+1, cost, dp) + cost[ind];
    int option2= fn(ind+2, cost, dp) + cost[ind];
    return dp[ind]= min(option1 , option2);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(fn(0,cost, dp), fn(1,cost, dp));
    }
};