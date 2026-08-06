class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool flag1=false, flag2=false, flag3=false;
        for(auto& it : triplets){
            if(it[0]>target[0] || it[1]>target[1] || it[2]>target[2]) continue;
            if(it[0]==target[0]) flag1=true;
            if(it[1]==target[1]) flag2=true;
            if(it[2]==target[2]) flag3=true;
        }
        return flag1 && flag2 && flag3;
    }
};