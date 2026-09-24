class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        int j=0;
        if(t.size()>s.size()) return "";
        unordered_map<char, int>mp;
        for(int i=0;i<t.size();i++) mp[t[i]]++;
        int cnt=0;
        int start=0;
        int minlen=INT_MAX;
        while(j<s.size()){
            if(mp[s[j]]>0){
                cnt++;
            }
            mp[s[j]]--;
            while(cnt==t.size()){
                int len=j-i+1;
                if(len<minlen){
                    start=i;
                    minlen=len;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) cnt--;
                i++;
            }
            j++;
        }
        return minlen==INT_MAX ? "" : s.substr(start, minlen);
    }
};