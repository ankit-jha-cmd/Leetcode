class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double>mpp;
        for(int i=0;i<position.size();i++){
            mpp[-position[i]]=(double)(target-position[i])/speed[i];
        }
        double currmaxtime=0;
        int fleet=0;
        for(auto it: mpp){
            if(it.second>currmaxtime){
                currmaxtime=it.second;
                fleet++;
            }
        }
        return fleet;
    }
};