class Solution {
public:
bool check(string &s, int i, int j, vector<vector<bool>>&dp){
    if(i>=j) return true;
    if(dp[i][j]!=0) return dp[i][j];
    if(s[i]!=s[j]) return false;
    return dp[i][j]= check(s, i+1, j-1, dp);
}
    string longestPalindrome(string s) {
        vector<vector<bool>>dp(s.size(), vector<bool>(s.size(), 0));
        int maxlen=INT_MIN;
        int sp=-1;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s,i,j, dp)){
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