class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char ch : num){
            while(!st.empty() && k > 0 && st.top() > ch)
            {
                st.pop();
                k--;
            }
            // ignoring any leading zero
            if(st.empty() == true && ch == '0'){
                continue;
            }
            else{
                st.push(ch); 
            }
        }
        //String in ascending order
        while(!st.empty() && k != 0)
        {
            st.pop();
            k--;
        }
        
        // if stack becomes empty
        if(st.empty() == true) 
        {
            return "0";
        }
        
        string res = "";
        while(st.empty() == false)
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;

    }
};

