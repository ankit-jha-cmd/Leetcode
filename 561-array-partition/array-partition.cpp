class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int maxi=0;
        for(int i=1;i<nums.size();i+=2){
            maxi+=nums[i];            
        }
        return maxi;
    }
};