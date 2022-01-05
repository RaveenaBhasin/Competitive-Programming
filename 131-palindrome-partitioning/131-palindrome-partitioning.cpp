class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while(start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    
    void solve(string& s, int currIndex, vector<string>&track, vector<vector<string>>&ans) {
        int n = s.size();
        if (currIndex == n) {
            ans.push_back(track);
        }
        else {
            for(int i = currIndex; i < n; i++) {
                if (isPalindrome(s, currIndex, i)) {
                    track.push_back(s.substr(currIndex, i - currIndex +1));
                    solve(s, i+1, track, ans);
                    track.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>track;
        solve(s, 0, track, ans);
        return ans;
    }
};