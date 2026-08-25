class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int el1=st.top(); st.pop();
                int el2=st.top(); st.pop();
                st.push(el2+el1);
            }

            else if(tokens[i]=="-"){
                int el1=st.top(); st.pop();
                int el2=st.top(); st.pop();
                st.push(el2-el1);
            }

            else if(tokens[i]=="*"){
                int el1=st.top(); st.pop();
                int el2=st.top(); st.pop();
                st.push(el2*el1);
            }

            else if(tokens[i]=="/"){
                int el1=st.top(); st.pop();
                int el2=st.top(); st.pop();
                st.push(el2/el1);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
