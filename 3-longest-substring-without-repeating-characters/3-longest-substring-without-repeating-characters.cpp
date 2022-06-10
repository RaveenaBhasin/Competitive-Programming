class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n = s.size(), res = 0;
        int i = 0, j = 0;
        while(i < n && j < n){
            if(st.find(s[j]) != st.end()){
                st.erase(s[i++]);
            }
            else{
                st.insert(s[j++]);
                res = max(res, j-i);
            }
        }
        return res;
    }
};

