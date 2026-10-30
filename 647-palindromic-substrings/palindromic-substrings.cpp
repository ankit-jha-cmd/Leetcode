class Solution {
public:
bool check(string &s, int i, int j, vector<vector<int>>&dp){
    if(i>=j) return true;
    if(dp[i][j]!=0) return dp[i][j];
    if(s[i]!=s[j]) return false;
    return dp[i][j]=check(s, i+1, j-1, dp);
}
    int countSubstrings(string s) {
        int cnt=0;
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), 0));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s, i, j, dp)) cnt++;
            }
        }
        return cnt;
    }
};