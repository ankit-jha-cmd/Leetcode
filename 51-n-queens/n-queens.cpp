class Solution {
public:
bool check(int r, int c, vector<string>& chess){
    for(int i=r-1;i>=0;i--){
        if(chess[i][c]=='Q') return false;
    }
    for(int i=r-1, j=c-1 ; i>=0 && j>=0; i--, j--){
        if(chess[i][j]=='Q') return false;
    }
    for(int i=r-1, j=c+1 ; i>=0 && j<chess.size(); i--, j++){
        if(chess[i][j]=='Q') return false;
    }
    return true;
}
void fn(vector<string>& chess, int n, int row, vector<vector<string>>&ans){
    if(row==n){
        ans.push_back(chess);
        return;
    }
    for(int i=0;i<n;i++){
        if(check(row, i, chess)){
            chess[row][i]='Q';
            fn(chess, n, row+1, ans);
            chess[row][i]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>chess(n, string(n, '.'));
        vector<vector<string>> ans;
        fn(chess, n, 0, ans);
        return ans;
    }
};