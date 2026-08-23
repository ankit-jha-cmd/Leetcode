class Solution {
public:
void fn(vector<int> &nums, vector<int>&arr, vector<vector<int>>&ans, int ind, int& k, int sum){
    if(sum>k) return;
    if(ind==nums.size()){
        if(sum==k) ans.push_back(arr);
        return;
    }
    arr.push_back(nums[ind]);
    fn(nums, arr, ans, ind+1, k, sum+nums[ind]);
    arr.pop_back();
    int next=ind+1;
    while(next<nums.size() && nums[next]==nums[ind]) next++;
    fn(nums, arr, ans, next, k, sum);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>arr;
        vector<vector<int>>ans;
        sort(candidates.begin(), candidates.end());
        fn(candidates, arr, ans, 0, target, 0);
        return ans;
    }
};