class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>arr;
        for(int i=0;i<speed.size();i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        stack<double>st;
        for(auto it: arr){
            double time= (double)(target-it.first)/it.second;
            if(st.empty() || time>st.top()) st.push(time);
        }
        return st.size();
    }
};