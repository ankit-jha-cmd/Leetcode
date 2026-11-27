class Solution {
public:
    int rob(vector<int>& nums) {
        int pick=0;
        int notPick=0;
        for(int i=nums.size()-1;i>=0;i--){
            int curr=  max(notPick, nums[i]+pick);
            pick=notPick;
            notPick=curr;
        }
        return max(pick, notPick);
    }
};