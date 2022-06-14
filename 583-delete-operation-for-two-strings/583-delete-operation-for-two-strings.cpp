class Solution {
public:
    int dp[501][501];
    int solve(string &a, string &b, int n, int m) {
        if(n == 0 && m == 0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(n == 0) return m;
        if(m == 0) return n;
        int cnt1 = INT_MAX, cnt2 = INT_MAX;
        if(a[n-1] == b[m-1]){
            return solve(a, b, n-1, m-1);
        }
        else{
            cnt1 = 1 + solve(a, b, n-1, m);
            cnt2 = 1 + solve(a, b, n, m-1);
        }
        return dp[n][m] = min(cnt1, cnt2);
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,word1.size(),word2.size());
    }
};
