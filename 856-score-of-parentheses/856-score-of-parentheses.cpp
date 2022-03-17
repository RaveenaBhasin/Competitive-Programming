class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] =='('){
                st.push(count);
                count = 0; //for next bracket(o/c)
            }
            else{
                count = max(2*count, 1) + st.top();
                st.pop();
            }
        }
        return count;
    }
};

