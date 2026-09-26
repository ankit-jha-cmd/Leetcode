class Solution {
public:
bool safe(int row, int col, vector<string>& chess, int n){
    for(int i=row-1;i>=0;i--) if(chess[i][col]=='Q') return false;

    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) if(chess[i][j]=='Q') return false;

    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) if(chess[i][j]=='Q') return false;

    return true;
}
void fn(int row, vector<string>& chess, int n, vector<vector<string>>& ans){
    if(row==n){
        ans.push_back(chess);
        return;
    }
    for(int col=0;col<n;col++){
        if(safe(row, col, chess, n)){
            chess[row][col]='Q';
            fn(row+1, chess, n, ans);
            chess[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>chess(n, string(n, '.'));
        vector<vector<string>>ans;
        fn(0, chess, n, ans);
        return ans;
    }
};