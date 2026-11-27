class Solution {
public:
int fn(vector<int>& nums, int ind, int end, vector<int>& dp){
    if(ind>=end) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick= nums[ind]+fn(nums, ind+2, end, dp);
    int notPick=  fn(nums, ind+1, end, dp);
    return dp[ind]=max(pick, notPick);
}
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp(nums.size()+1, -1);
        int robFirstHouse= fn(nums, 0, nums.size()-1, dp);
        for(int i=0;i<dp.size();i++) dp[i]=-1;
        int robLastHouse= fn(nums, 1, nums.size(), dp);
        return max(robFirstHouse, robLastHouse);
    }
};