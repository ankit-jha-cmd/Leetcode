class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>sorted;
        for(int i=0;i<speed.size();i++){
            sorted.push_back({position[i],i});
        }
        vector<int>t;
        // for(int x:position)t.push_back(x); 
        sort(sorted.begin(), sorted.end(), greater<pair<int,int>>());
        int carfleet=0;
        double time=-1.0;
        for(int i=0;i<sorted.size();i++){
            int pos=sorted[i].first;
            int ind=sorted[i].second;
            int sp=speed[ind];
            double maxtime= (double)(target-pos)/sp;
            if(maxtime>time){
                time=maxtime;
                carfleet++;
            }
        }
        return carfleet;
    }
};