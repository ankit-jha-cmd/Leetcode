class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]].second=i;
            }
            else mp[s[i]]={i,i};
        }
        vector<pair<int, int>>arr;
        for(auto it: mp){
            arr.push_back(it.second);
        }
        sort(arr.begin(), arr.end());
        int i=0;
        int j=1;
        vector<int>ans;
        while(j<arr.size()){
            if(arr[j].first<arr[i].second){
                arr[i].second=max(arr[i].second, arr[j].second);
            }
            else{
                ans.push_back(arr[i].second-arr[i].first+1);
                i=j;
            }
            j++;
        }
        ans.push_back(arr[i].second-arr[i].first+1);
        return ans;
    }
};