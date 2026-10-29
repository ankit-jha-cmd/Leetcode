class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26, 0);
        int mf=0;
        int ml=0;
        int i=0;
        int j=0;
        while(j<s.size()){
            freq[s[j]-'A']++;
            mf=max(mf, freq[s[j]-'A']);
            while((j-i+1)-mf>k){
                freq[s[i]-'A']--;
                i++;
            }
            ml=max(ml, j-i+1);
            j++;
        }
        return ml;
    }
};