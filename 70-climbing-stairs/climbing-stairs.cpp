class Solution {
public:
int fn(vector<int>& dp, int n){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fn(dp, n-1)+fn(dp, n-2);
}
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return fn(dp, n);
    }
};