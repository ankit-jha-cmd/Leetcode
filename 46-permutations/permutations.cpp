class Solution {
public:
void findPermutations(vector<int>& nums, int ind, vector<int>& vis, vector<int>& arr, vector<vector<int>>& ans){
    if(ind>=nums.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!vis[i]){
            arr.push_back(nums[i]);
            vis[i]=1;
            findPermutations(nums, ind+1, vis, arr, ans);
            arr.pop_back();
            vis[i]=0;
        }
    }
    
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>arr;
        vector<vector<int>>ans;
        vector<int>vis(nums.size(), 0);
        findPermutations(nums, 0, vis, arr, ans);
        return ans;
    }
};