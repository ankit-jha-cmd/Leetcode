class Solution {
public:
vector<int>findrm(vector<int>& arr){
    int n=arr.size();
    vector<int>rm(n);
    rm[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        rm[i]=max(arr[i], rm[i+1]);
    }
    return rm;
}

vector<int>findlm(vector<int>& arr){
    int n=arr.size();
    vector<int>lm(n);
    lm[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        lm[i]=max(arr[i], lm[i-1]);
    }
    return lm;
}
    int trap(vector<int>& height) {
        int total=0;
        vector<int>leftmax= findlm(height);
        vector<int>rightmax= findrm(height);
        for(int i=0;i<height.size();i++){
            if(leftmax[i]>height[i] && rightmax[i]>height[i]){
                total+= min(leftmax[i],rightmax[i])-height[i];
            }
        }
        return total;
    }
};