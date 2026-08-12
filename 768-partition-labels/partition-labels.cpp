class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()) mp[s[i]]={i,i};
            else mp[s[i]].second=i;
        }
        vector<pair<int, int>>check;
        for(auto it:mp){
            check.push_back({it.second.first, it.second.second});
        }
        sort(check.begin(), check.end());
        int start=check[0].first;
        int end=check[0].second;
        vector<int>res;
        for(int i=1;i<check.size();i++){
            if(check[i].first<=end){
                end=max(end, check[i].second);
            }
            else{
                res.push_back(end-start+1);
                start=check[i].first;
                end=check[i].second;
            }
        }
        res.push_back(end-start+1); 
        return res;
    }
};
