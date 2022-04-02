class Solution {
    bool isPal(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while(start < end){
            if(s[start] != s[end]){
                return isPal(s, start+1, end) || isPal(s, start, end-1);
            }
            start++;
            end--;
        }
        return true;
    }
};














