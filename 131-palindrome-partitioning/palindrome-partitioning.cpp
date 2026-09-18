class Solution {
public:
bool check(string& s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void fn(string &s, int ind, vector<string>&part, vector<vector<string>>&ans){
    if(ind>=s.size()){
        ans.push_back(part);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(check(s,ind,i)){
            part.push_back(s.substr(ind, i-ind+1));
            fn(s,i+1,part,ans);
            part.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>part;
        vector<vector<string>>ans;
        fn(s, 0, part, ans);
        return ans;
    }
};