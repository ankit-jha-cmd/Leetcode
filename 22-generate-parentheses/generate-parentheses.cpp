class Solution {
public:
void fn(int n, string &arr, vector<string>&ans, int opcnt, int clcnt){
    if(opcnt==n && clcnt==n){
        ans.push_back(arr);
    }

    if(opcnt<n){
        arr.push_back('(');
        fn(n, arr, ans, opcnt+1, clcnt);
        arr.pop_back();
    }

    if(clcnt<opcnt){
        arr.push_back(')');
        fn(n, arr, ans, opcnt, clcnt+1);
        arr.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        string arr;
        vector<string>ans;
        fn(n, arr, ans, 0, 0);
        return ans;
    }
};