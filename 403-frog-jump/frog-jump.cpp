class Solution {
public:
bool fn(vector<int>& arr, int r, int ind, unordered_map<int, int>& mp, int j, vector<vector<int>>&dp){
    if(r==arr[arr.size()-1]) return true;
    if(j==0) return false;
    if(dp[ind][j]!=-1) return dp[ind][j];
    bool possible=false;
    for(int k=j-1;k<=j+1;k++){
        if(k<=0) continue;
        int nextReach=arr[ind]+k;
        if(mp.find(nextReach)!=mp.end()){
            int nextInd=mp[nextReach];
            possible=possible || fn(arr, nextReach, nextInd, mp, k, dp);
        }
    }
    return dp[ind][j]=possible;
}
    bool canCross(vector<int>& stones) {
        unordered_map<int, int>mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        vector<vector<int>>dp(stones.size()+1, vector<int>(stones.size()+1, -1));
        if(stones[1]>1) return false;
        return fn(stones, 1, 1, mp, 1, dp);
    } 
};