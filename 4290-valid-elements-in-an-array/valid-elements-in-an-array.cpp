class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            bool leftvalid=true;
            for(int j=0;j<i;j++){
                if(nums[i]<=nums[j]){
                    leftvalid=false;
                    break;
                }
            }
            bool rightvalid=true;
            if(!leftvalid){
                for(int k=i+1;k<nums.size();k++){
                    if(nums[i]<=nums[k]){
                        rightvalid=false;
                        break;
                    }
                }
            }
            if(leftvalid || rightvalid){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};