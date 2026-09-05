class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        if(n>m) return false;
        unordered_map<char, int>rn;
        unordered_map<char, int>mg;
        for(int i=0;i<n;i++) rn[ransomNote[i]]++;
        for(int i=0;i<m;i++) mg[magazine[i]]++;
        for(auto it: rn){
            if(it.second > mg[it.first]) return false;
        }
        return true;
    }
};