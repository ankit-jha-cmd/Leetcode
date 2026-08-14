class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        long long rev=0;
        if(num<0) return false;
        while(num>0){
            int digit=num%10;
            rev= 1LL * rev*10 + digit;
            num/=10;
        }
        return rev==x;
    }
};