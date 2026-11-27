class Solution {
public:
    int rob(vector<int>& nums) {
        int next1=0;
        int next2=0;
        for(int i=nums.size()-1;i>=0;i--){
            int curr=  max(next2, nums[i]+next1);
            next1=next2;
            next2=curr;
        }
        return next2;
    }
};