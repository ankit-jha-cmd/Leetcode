class Solution {
public:
void fn(vector<int>& nums, int k, int ind, int sum, vector<int>&arr,
vector<vector<int>>& ans){
    if(sum>k) return;
    if(sum==k){
        ans.push_back(arr);
        return;
    }
    if(ind==nums.size()) return;

    arr.push_back(nums[ind]);
    fn(nums, k, ind, sum+nums[ind], arr, ans);
    arr.pop_back();
    fn(nums, k, ind+1, sum, arr, ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>arr;
        vector<vector<int>>ans;
        fn(candidates, target, 0, 0, arr, ans);
        return ans;
    }
};