class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxi=0;
        while(i<j){
            maxi= max(maxi, min(height[j], height[i])* (j-i));
            if(height[j]<height[i]) j--;
            else i++;
        }
        return maxi;
    }
};