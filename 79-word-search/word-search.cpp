class Solution {
public:
bool fn(int row, int col, int cnt, string &word, vector<vector<char>>& board){
    if(cnt==word.size()) return true;
    if((row<0 || row>=board.size()) || (col<0 || col>=board[0].size())) return false;
    if(board[row][col]!=word[cnt]) return false;
    char temp= board[row][col];
    board[row][col]='#';
    bool correct= 
    fn(row-1, col, cnt+1, word, board)||
    fn(row, col+1, cnt+1, word, board)||
    fn(row+1, col, cnt+1, word, board)||
    fn(row, col-1, cnt+1, word, board);
    board[row][col]=temp;
    return correct;
}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(fn(i,j, 0, word, board)) return true;
            }
        }
        return false;
    }
};