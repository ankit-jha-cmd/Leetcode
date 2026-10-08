class Solution {
public:
bool check(int i, int j, string s){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}
void fn(string &s, vector<string>&arr, vector<vector<string>>&ans, int ind){
    if(ind==s.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(check(ind, i, s)){
            arr.push_back(s.substr(ind, i-ind+1));
            fn(s, arr, ans, i+1);
            arr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>arr;
        vector<vector<string>>ans;
        fn(s, arr, ans, 0);
        return ans;
    }
};