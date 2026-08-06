class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int, int>mpp;
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }
        while(!mpp.empty()){
            int mini= mpp.begin()->first;
            mpp[mini]--;
            if(mpp[mini]==0)mpp.erase(mini);
            for(int i=1;i<groupSize;i++){
                if(mpp.find(mini+1)==mpp.end()) return false;
                mini=mini+1;
                mpp[mini]--;
                if(mpp[mini]==0)mpp.erase(mini);
            }
        }
        return true;
    }
};