class Solution {
public:
    int countDistinct(string s, string t, int i, int j, vector<vector<int>>&dp) {
        if(i < j) return 0;
        if(j < 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) {
            return dp[i][j] = countDistinct(s, t, i-1, j-1, dp) + countDistinct(s, t, i-1, j, dp);
        }
        else {
            return dp[i][j] = countDistinct(s, t, i-1, j, dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return countDistinct(s, t, n-1, m-1, dp);
    }
};