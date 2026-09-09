class Solution {
public:
bool checkfn(vector<int>& piles, int h, int mid){
    int speed=0;
    for(int i=0;i<piles.size();i++){
        speed+= ceil((double)piles[i]/mid);
        if(speed>h) return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int maxi=0;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi, piles[i]);
        }
        int e=maxi;
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(checkfn(piles, h, mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};
