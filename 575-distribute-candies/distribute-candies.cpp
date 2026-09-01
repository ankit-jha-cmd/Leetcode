class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>st;
        for(int i=0;i<candyType.size();i++) st.insert(candyType[i]);
        int n=st.size();
        int m=  candyType.size()/2;
        return min(n,m);   
    }
};