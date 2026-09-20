class Solution {
public:
void fn(string& nums, int ind, string& arr, vector<string>&ans, map<char, string>&mp){
    if(ind==nums.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=0;i<mp[nums[ind]].size();i++){
        arr.push_back(mp[nums[ind]][i]);
        fn(nums, ind+1, arr, ans, mp);
        arr.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        string arr;
        vector<string>ans;
        map<char, string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        fn(digits, 0, arr, ans, mp);
        return ans;
    }
};