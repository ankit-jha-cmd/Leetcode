class TimeMap {
public:
unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        vector<pair<int, string>>&vec=mp[key];
        string ans="";
        int s=0;
        int e=vec.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(vec[mid].first<=timestamp){
                ans=vec[mid].second;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ans;
    }
};
