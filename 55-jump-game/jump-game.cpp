class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump=0;
        int i=0;
        while(i<nums.size()){
            maxJump=max(maxJump, i+nums[i]);
            i++;
            if(maxJump>=nums.size()-1) return true;
            if(i>maxJump) return false;
        }
        return false;
    }
};