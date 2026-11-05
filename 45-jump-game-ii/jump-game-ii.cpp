class Solution {
public:
    int jump(vector<int>& nums) {
        int j=0;
        int mj=0;
        int jumps=0;
        if(nums.size()==1) return 0;
        for(int i=0;i<nums.size();i++){
            mj=max(mj, i+nums[i]);
            if(i==j){
                jumps++;
                j=mj;
            }
            if(j>=nums.size()-1) return jumps;
        }
        return -1;
    }
};