class Solution {
public:
vector<int>psefn(vector<int>& arr){
    int n=arr.size();
        vector<int>ans(n, -1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
}
vector<int>nsefn(vector<int>& arr){
    int n=arr.size();
     stack<int>st;
        vector<int>ans(n, arr.size());
        for(int i=0;i<n;i++){
                while(!st.empty() && arr[i]<arr[st.top()]){
                    ans[st.top()]=i;
                    st.pop();
                }    
                st.push(i);
        }
        return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        vector<int>nse=nsefn(heights);
        vector<int>pse = psefn(heights);
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};