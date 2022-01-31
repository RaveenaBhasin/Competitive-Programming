class Solution {
public:
    int unbounded(vector<int>&v, int currIndex, int amount, vector<vector<int>>&dp) {
        if(amount == 0){
            return 0;
        }
        if(currIndex >= v.size()){
            return 100000;
        }
        if(dp[currIndex][amount] != -1){
            return dp[currIndex][amount];
        }
        int consider = 100000;
        if(v[currIndex] <= amount){
            consider = 1 + unbounded(v, currIndex, amount - v[currIndex], dp);
        }
        int notConsider = unbounded(v, currIndex + 1, amount, dp);
        return dp[currIndex][amount] = min(consider, notConsider);
        
    }

    int numSquares(int n) {

        vector<int>ans;
        for(int i = 1; i*i <= n; i++){
            ans.push_back(i*i);
        }
        vector<vector<int>>dp(ans.size()+1, vector<int>(n + 1, -1));
        int res = unbounded(ans, 0, n, dp);
        if(res == 100000){
            return -1;
        }
        else{
            return res;
        }
    }
};