class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int>mp;
        for(int i=0;i<score.size();i++) mp[score[i]]=i;
        sort(score.begin(), score.end(), greater<int>());
        vector<string>ans(score.size());
        for(int i=0;i<score.size();i++){
            if(i==0) ans[mp[score[0]]]="Gold Medal";
            else if(i==1) ans[mp[score[1]]]="Silver Medal";
            else if(i==2) ans[mp[score[2]]]="Bronze Medal";
            else ans[mp[score[i]]]=to_string(i+1);
        }
        return ans;
    }
};