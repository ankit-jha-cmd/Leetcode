class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0;
        int e=(n*m)-1;
        while(s<=e){
            int mid=(s+e)/2;
            int r= mid/m;
            int c= mid%m;
            if(matrix[r][c]==target) return true;
            if(matrix[r][c]<target) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};