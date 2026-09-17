class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m)return "";
        string ans="";
        int minlen=INT_MAX;
        int i=0;
        int j=0;
        int cnt=0;
        int start=0;
        unordered_map<char, int>mp;
        for(int i=0;i<m;i++) mp[t[i]]++;
        while(j<n){
            if(mp[s[j]]>0) cnt++;
            mp[s[j]]--;
            while(cnt==m){
                if((j-i+1)<minlen){
                    minlen=j-i+1;
                    start=i;
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