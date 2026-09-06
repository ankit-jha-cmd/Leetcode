class Solution {
public:
vector<int> findpse(vector<int>& arr, int n){
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<arr[st.top()]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<int> findnse(vector<int>& arr, int n){
    stack<int>st;
    vector<int>ans(n,n);
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
        int n=heights.size();
        vector<int>nse=findnse(heights, n);
        vector<int>pse=findpse(heights, n);
        int maxarea=0;
        for(int i=0;i<n;i++){
           maxarea=max(maxarea, heights[i]*(nse[i]-pse[i]-1)); 
        }
        return maxarea;
    }
};