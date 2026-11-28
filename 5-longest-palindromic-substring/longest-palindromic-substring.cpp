class Solution {
public:
bool check(string& s, int i, int j, vector<vector<int>>& dp){
    if(i>=j) return true;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]!=s[j]) return dp[i][j]=0;
    return dp[i][j]=check(s, i+1, j-1, dp);
}
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));
        int sp=-1;
        int maxlen=INT_MIN;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s, i, j, dp)){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};