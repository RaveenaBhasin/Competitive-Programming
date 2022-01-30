class Solution {
public:
    bool isValid(string s) {     
        stack<char>st;
        for(auto it : s){
            //opening bracket
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }
            //closing but check for similiar opening bracket
            else{
                if(st.empty() || (st.top() == '(' && it != ')') || (st.top() == '{' && it != '}') || (st.top() == '[' && it != ']')){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};