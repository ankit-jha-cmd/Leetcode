class Solution {
public:
bool check(string& s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    string longestPalindrome(string s) {
        int sp=-1;
        int maxlen=INT_MIN;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s, i, j)){
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