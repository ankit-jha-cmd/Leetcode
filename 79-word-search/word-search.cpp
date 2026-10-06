class Solution {
public:
bool fn(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col, string& word, int ind){
    if(ind==word.size()){
        return true;
    }
    if((row<0 || row>=board.size()) || (col<0 || col>=board[0].size())) return false;
    if(board[row][col]!=word[ind]) return false;
    if(!vis[row][col]){
        vis[row][col]=1;
        bool correct=
        fn(board, vis, row, col+1, word, ind+1)||
        fn(board, vis, row+1, col, word, ind+1)||
        fn(board, vis, row, col-1, word, ind+1)||
        fn(board, vis, row-1, col, word, ind+1);
        vis[row][col]=0;
        return correct;
    }
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(fn(board, vis, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};