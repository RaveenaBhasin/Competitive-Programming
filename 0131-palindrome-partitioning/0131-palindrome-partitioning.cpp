class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void helper(string s, int currIndex, vector<string>&curr, vector<vector<string>>&res){
        int n = s.size();
        if(currIndex == n) {
            res.push_back(curr);
        }
        else {
            for(int i = currIndex; i < n; i++) {
                if(isPalindrome(s, currIndex, i)) {
                    curr.push_back(s.substr(currIndex, i-currIndex+1));
                    helper(s, i+1, curr, res);
                    curr.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>curr;
        helper(s, 0, curr, res);
        return res;
    }
};