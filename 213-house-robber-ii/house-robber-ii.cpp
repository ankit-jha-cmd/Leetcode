class Solution {
public:
int fn1(vector<int>&nums, int n){
    int next1=0;
    int next2=0;
    for(int i=n-2;i>=0;i--){
        int curr=max(next1, nums[i]+next2);
        next2=next1;
        next1=curr;
    }
    return next1;
}
int fn2(vector<int>&nums, int n){
    int next1=0;
    int next2=0;
    for(int i=n-1;i>0;i--){
        int curr=max(next1, nums[i]+next2);
        next2=next1;
        next1=curr;
    }
    return next1;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(fn1(nums, n), fn2(nums, n));
    }
};