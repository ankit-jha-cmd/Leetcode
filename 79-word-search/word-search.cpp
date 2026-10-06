class Solution {
public:
bool fn(vector<vector<char>>& board, int row, int col, string& word, int ind){
    if(ind==word.size()){
        return true;
    }
    if((row<0 || row>=board.size()) || (col<0 || col>=board[0].size())) return false;
    if(board[row][col]!=word[ind]) return false;
    char temp = board[row][col];
    board[row][col]='#';
    bool correct=
    fn(board, row, col+1, word, ind+1)||
    fn(board, row+1, col, word, ind+1)||
    fn(board, row, col-1, word, ind+1)||
    fn(board, row-1, col, word, ind+1);
    board[row][col]=temp;
    return correct;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(fn(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};