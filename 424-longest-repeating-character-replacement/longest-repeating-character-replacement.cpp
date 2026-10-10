class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        vector<int>freq(26);
        int maxfreq=0;
        int maxlen=0;
        while(j<s.size()){
            freq[s[j]-'A']++;
            maxfreq=max(maxfreq, freq[s[j]-'A']);
            while(k < ((j-i+1) - maxfreq)){
                freq[s[i]-'A']--;
                i++;
            }
            maxlen=max(maxlen, (j-i+1));
            j++;
        }
        return maxlen;
    }
};