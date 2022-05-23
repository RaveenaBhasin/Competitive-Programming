class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        map<int, pair<int, int>>mp;
        int i = 0;
        for(auto it : strs){
            int zero = 0, ones = 0;
            for(auto x : it){
                if(x == '1'){
                    ones++;
                }
                else{
                    zero++;
                }
            }
            mp[i] = {zero, ones};
            i++;
        }
        vector<vector<vector<int>>>dp(len+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i = 1; i <= len; i++){
            int zeros = mp[i-1].first, ones = mp[i-1].second;
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if(j-zeros >= 0 && k-ones >= 0){
                        dp[i][j][k] = max(dp[i-1][j][k], 1+dp[i-1][j-zeros][k-ones]);
                    }
                    else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[len][m][n] ;
    }
};

