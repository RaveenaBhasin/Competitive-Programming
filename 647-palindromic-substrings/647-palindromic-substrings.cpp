class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            int start = i, end = i;
            while(start >= 0 && end < s.size() && s[start] == s[end]){
                res++;
                start--;
                end++;
            }
            start = i, end = i + 1;
            while(start >= 0 && end < s.size() && s[start] == s[end]){
                res++;
                start--;
                end++;
            }
        }
        return res;
    }
};