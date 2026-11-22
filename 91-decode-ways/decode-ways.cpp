class Solution {
public:
int fn(string &s, int ind, vector<int>& dp){
    if(ind>=s.size()) return 1;
    if(s[ind]=='0') return 0;
    if(dp[ind]!=-1) return dp[ind];
    int one=fn(s, ind+1, dp);
    int two=0;
    if(ind+1<s.size()){
        if(stoi(s.substr(ind, 2))<=26){
            two=fn(s, ind+2, dp);
        }
    }
    return dp[ind]=one+two;
}
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, -1);
        return fn(s, 0, dp);
    }
};