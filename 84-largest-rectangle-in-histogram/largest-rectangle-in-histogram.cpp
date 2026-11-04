class Solution {
public:

vector<int>findsmallestright(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size(), arr.size());
    for(int i=0;i<arr.size(); i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int>findsmallestleft(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size(), -1);
    for(int i=arr.size()-1;i>=0; i--){
        while(!st.empty() && arr[st.top()]>arr[i]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>smallestleft=findsmallestleft(heights);
        vector<int>smallestright=findsmallestright(heights);
        int maxarea=0;
        for(int i=0;i<heights.size();i++){
            int area= heights[i]*(smallestright[i]-smallestleft[i]-1);
            maxarea=max(maxarea, area);
        }
        return maxarea;
    }
};