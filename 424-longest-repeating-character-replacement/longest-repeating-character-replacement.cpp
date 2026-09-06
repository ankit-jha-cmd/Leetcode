class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26);
        int maxlen=0;
        int maxfreq=0;
        int i=0; int j=0;
        while(j<s.size()){
            freq[s[j]-'A']++;
            maxfreq=max(maxfreq, freq[s[j]-'A']);
            while((j-i+1)-maxfreq>k){
                freq[s[i]-'A']--;
                i++;
            }
            maxlen=max(maxlen, (j-i+1));
            j++;
        }
        return maxlen;
    }
};