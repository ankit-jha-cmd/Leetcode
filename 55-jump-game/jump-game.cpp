class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int maxi=0;
        if(nums.size()==1) return true;
        while(i<nums.size()){
            int potential = i+nums[i];
            maxi= max(maxi, potential);
            i++;
            if(i>maxi) return false;
            if(potential>=nums.size()-1) return true;
        }
        return true;
    }
};