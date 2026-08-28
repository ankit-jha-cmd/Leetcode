class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=0;
        int n=height.size();
        int ans=0;
        while(i<n-1){
            j=i+1;
            while(j<n && height[j]<height[i]) j++;
            if(j>=n){
                j=i+1;
                for(int k=i+1;k<n;k++){
                    if(height[k]>height[j]) j=k;
                }
            }
            int supposed= min(height[i], height[j]) * (j-i-1);
            i++;
            while(i<j){
                supposed-=height[i];
                i++;
            }
            ans+=supposed;
        }
        return ans;
    }
};
