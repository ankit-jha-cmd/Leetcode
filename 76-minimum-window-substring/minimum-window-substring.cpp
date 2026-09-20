class Solution {
public:
    string minWindow(string s, string t) {
        int i=0; int j=0;
        int minlen=INT_MAX;
        int cnt=0;
        int start=0;
        if(t.size()>s.size()) return "";
        unordered_map<int, int>mp;
        for(int i=0;i<t.size();i++) mp[t[i]]++;
        while(j<s.size()){
            if(mp[s[j]]>0){
                cnt++;
            }
            mp[s[j]]--;
            while(cnt==t.size()){
                if((j-i+1)<minlen){
                    minlen=j-i+1;
                    start=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return minlen==INT_MAX? "" : s.substr(start, minlen);
    }
};