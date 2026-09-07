class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int cnt=0;
        int minlen=INT_MAX;
        int start=0;
        if(s.size()<t.size()) return "";
        vector<int>freq(128,0);
        for(char c: t) freq[c]++;
        while(r<s.size()){
            if(freq[s[r]]>0) cnt++;
            freq[s[r]]--;
            while(cnt == t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    start=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return minlen==INT_MAX? "" : s.substr(start, minlen);
    }
};