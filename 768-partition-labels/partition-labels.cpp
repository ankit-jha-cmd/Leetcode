class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int, int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()) mp[s[i]]={i,i};
            else mp[s[i]].second=i;
        }
        map<int, int>byfirst;
        for(auto it : mp){
            byfirst[it.second.first]=it.second.second;
        }
        vector<pair<int, int>>arr;
        for(auto& p : byfirst){
            arr.push_back(p);
        }
        vector<int>ans;
        int i=0;
        int j=1;
        while(j<arr.size()){
            if(arr[j].first <= arr[i].second){
                arr[i].second=max(arr[i].second, arr[j].second);
            }
            else{
                ans.push_back(arr[i].second - arr[i].first + 1);
                i=j;
            }
            j++;
        }
        ans.push_back(arr[i].second - arr[i].first + 1);
        return ans;
    }
};