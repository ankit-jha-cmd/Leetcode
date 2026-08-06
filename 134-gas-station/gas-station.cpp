class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int resind=0;
        int gasleft=0;
        int totalgasleft=0;
        int i=0;
        while(i<gas.size()){
            gasleft+=gas[i]-cost[i];
            totalgasleft+=gas[i]-cost[i];
            if(gasleft<0){
                resind=i+1;
                gasleft=0;
            }
            i++;
        }
        if(totalgasleft<0) return -1;
        return resind;
    }
};