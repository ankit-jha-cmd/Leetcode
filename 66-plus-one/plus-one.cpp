class Solution {
public:
vector<int>specialcase(vector<int>&arr){
    reverse(arr.begin(), arr.end());
    int i=0;
    while(i<arr.size() && arr[i]==9){
        arr[i]=0;
        i++;
    }
    if(i<arr.size()) arr[i]+=1;
    else arr.push_back(1);
    reverse(arr.begin(), arr.end());
    return arr;
}
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]==9) return specialcase(digits);
        digits[digits.size()-1]+=1;
        return digits;
    }
};