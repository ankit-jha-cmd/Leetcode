class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int i=0;
        int cnt=0;
        while(s[i]==' '){
            i++;
            cnt++;
        }
        while(i<s.size() && s[i]!=' '){
            i++;
        }
        return i-cnt;
    }
};