class Solution {
public:
    bool checkValidString(string s) {
        int minrange=0;
        int maxrange=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                minrange++;
                maxrange++;
            }
            else if(s[i]==')'){
                minrange--;
                maxrange--;
            }
            else {
                minrange--;
                maxrange++;
            }
                if(maxrange<0) return false;
                minrange=max(0, minrange);
        }
        return minrange==0;
    }
};