class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        if(s2.size()<n) return false;
        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2) return true;
        for(int i=n;i<s2.size();i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-n]-'a']--;
            if(freq1==freq2) return true;
        }
        return false;
    }
};
