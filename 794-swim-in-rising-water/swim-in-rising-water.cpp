class Solution {
public:
bool dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int t, int r, int c){
    if(r<0 || c<0 || r>=n || c>=n || vis[r][c] || grid[r][c]>t) return false;
    if(r==n-1 && c==n-1) return true;
    vis[r][c]=1;
    bool correct=
    dfs(grid, vis, n, t, r-1, c)||
    dfs(grid, vis, n, t, r, c+1)||
    dfs(grid, vis, n, t, r+1, c)||
    dfs(grid, vis, n, t, r, c-1);
    return correct;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int s=grid[0][0];
        int e=n*n-1;
        int ans=-1;
        while(s<=e){
            vector<vector<int>>vis(n, vector<int>(n,0));
            int mid=(s+e)/2;
            if(dfs(grid, vis, n, mid, 0,0)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};