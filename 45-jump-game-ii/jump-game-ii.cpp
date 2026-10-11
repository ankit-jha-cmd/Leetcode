class Solution {
public:
    int jump(vector<int>& nums) {
        int maxJump=0;
        int totalJumps=0;
        int n=nums.size();
        int end=0;
        if(n==1) return 0;
        for(int i=0;i<n;i++){
            maxJump=max(maxJump, i+nums[i]);
            if(i==end){
                totalJumps++;
                end=maxJump;
            }
            if(end >= n-1) return totalJumps;
        }
        return -1;
    }
};