class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int maxjump=0;
        int j=0;
        if(nums.size()==1) return 0;
        for(int i=0;i<nums.size();i++){
            maxjump=max(maxjump, i+nums[i]);
            if(i==j){
                jumps++;
                j=maxjump;
            }
            if(j>=nums.size()-1) return jumps;
        }
        return -1;
    }
};