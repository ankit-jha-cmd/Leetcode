class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            int top_el=pq.top();
            if(nums[i]>top_el){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};