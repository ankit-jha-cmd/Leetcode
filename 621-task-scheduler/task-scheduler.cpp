class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        unordered_map<char, int>freq;
        unordered_map<char, int>free_;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;
            free_[tasks[i]]=1;
        }
        int slot=1;
        vector<pair<int, char>>cooldown;
        priority_queue<pair<int, char>>pq;
        for(auto it: freq) pq.push({it.second, it.first});
        while(!pq.empty() || !cooldown.empty()){
            vector<pair<int, char>>stillWaiting;
                for(int i=0;i<cooldown.size();i++){
                    if(slot>= free_[cooldown[i].second]) pq.push(cooldown[i]);
                    else stillWaiting.push_back(cooldown[i]);
                }
                cooldown=stillWaiting;
                if(pq.empty()){
                    slot++;
                    continue;
                }
                auto el=pq.top();
                pq.pop();
                char val=el.second;
                int occ=el.first-1;
                free_[val]=slot+n+1;
                if(occ>=1) cooldown.push_back({occ, val});
                slot++;
            }
        return slot-1;
    }
};
