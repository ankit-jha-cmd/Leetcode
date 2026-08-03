class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>freq;
        for(int i=0;i<tasks.size();i++) freq[tasks[i]]++;
        priority_queue<int>pq;
        for(auto it: freq) pq.push(it.second);
        queue<pair<int, int>>cooldown;
        int slot=0;
        while(!pq.empty() || !cooldown.empty()){
            slot++;
            if(!pq.empty()){
                int occ=pq.top();
                pq.pop();
                occ--;
                if(occ>0) cooldown.push({occ, slot+n});
            }
            if(!cooldown.empty() && cooldown.front().second==slot){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return slot;
    }
};