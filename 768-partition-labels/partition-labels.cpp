class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char, pair<int, int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()) mp[s[i]]={i,i};
            else mp[s[i]].second=i;
        }
        vector<pair<int, int>>arr;
        for(auto it: mp){
            int a=it.second.first;
            int b=it.second.second;
            arr.push_back({a,b});
        }
        sort(arr.begin(), arr.end());
        int a=arr[0].first;
        int b=arr[0].second;
        for(int i=0;i<arr.size();i++){
            if(arr[i].first<=b){
                b=max(b,arr[i].second);
            }
            else{
                ans.push_back(b-a+1);
                a=arr[i].first;
                b=arr[i].second;
            }
        }
        ans.push_back(b-a+1);
        return ans;
    }
};