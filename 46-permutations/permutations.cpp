class Solution {
public:

void fn(vector<int>& nums, vector<int>&arr, vector<int>& vis, vector<vector<int>>&ans){
    if(arr.size()==nums.size()){
        ans.push_back(arr);
        return;
    }    

    for(int i=0;i<nums.size();i++){
        if(!vis[i]){
            vis[i]=1;
            arr.push_back(nums[i]);
            fn(nums, arr, vis, ans);
            arr.pop_back();
            vis[i]=0;
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>arr;
        vector<vector<int>>ans;
        vector<int>vis(nums.size(), 0);
        fn(nums, arr, vis, ans);
        return ans;
    }
};
