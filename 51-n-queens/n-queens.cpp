class Solution {
public:
    bool checkfn(int r, int c, vector<string>& chess) {
        int row=r;
        int col=c;
        while (row >= 0) {
            if (chess[row][c] == 'Q')
                return false;
                row--;
        }
        row=r;
        col=c;
        while (row >= 0 && col>=0) {
            if (chess[row][col] == 'Q')
                return false;
                row--;
                col--;
        }
        row=r;
        col=c;
        while (row >= 0 && col < chess.size()) {
            if (chess[row][col] == 'Q')
                return false;
                row--;
                col++;
        }
        return true;
    }
    void fn(int row, vector<string>& chess, vector<vector<string>>& ans) {
        if (row == chess.size()) {
            ans.push_back(chess);
            return;
        }
        for (int i = 0; i < chess[0].size(); i++) {
            if (checkfn(row, i, chess)) {
                chess[row][i] = 'Q';
                fn(row + 1, chess, ans);
                chess[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        vector<vector<string>> ans;
        fn(0, chess, ans);
        return ans;
    }
};