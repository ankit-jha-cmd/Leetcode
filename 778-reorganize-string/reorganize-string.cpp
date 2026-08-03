class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>freq;
        for(int i=0;i<s.size();i++) freq[s[i]]++;
        priority_queue<pair<int, char>>pq;
        for(auto it: freq){
            pq.push({it.second, it.first});
            if(pq.top().first>(s.size()+1)/2) return "";
        }
        string ans;
        pair<int,char>prev={0, '#'};
        while(!pq.empty()){
            auto el= pq.top();
            pq.pop();
            ans+=el.second;
            el.first--;
            if(prev.first>0){
                pq.push(prev);
            }
            prev=el;
        }
        return ans;
    }
};