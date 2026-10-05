class Solution {
public:
void fn(vector<int>& nums, vector<int>&vis, vector<int>&arr, vector<vector<int>>&ans){
    if(arr.size()==nums.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!vis[i]){
            vis[i]=1;
            arr.push_back(nums[i]);
            fn(nums, vis, arr, ans);
            arr.pop_back();
            vis[i]=0;
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>vis(nums.size(), 0);
        vector<int>arr;
        vector<vector<int>>ans;
        fn(nums, vis, arr, ans);
        return ans;
    }
};