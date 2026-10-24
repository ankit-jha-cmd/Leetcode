class Solution {
public:
bool fn(int row, int col, int ind, vector<vector<char>>& grid, string& word){
    if(ind==word.size()){
        return true;
    }
    if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) return false;
    int letter=word[ind];
    if(grid[row][col]!=letter) return false;
    char temp=grid[row][col];
    grid[row][col]='#';
    bool correct=
    fn(row-1, col, ind+1, grid, word)||
    fn(row, col+1, ind+1, grid, word)||
    fn(row+1, col, ind+1, grid, word)||
    fn(row, col-1, ind+1, grid, word);
    grid[row][col]=temp;
    return correct;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int ind=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(fn(i,j,0,board, word)) return true;
            }
        }
        return false;
    }
};