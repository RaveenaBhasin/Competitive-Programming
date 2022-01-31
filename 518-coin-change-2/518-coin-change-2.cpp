class Solution {
public:
    int unbounded(vector<int>&coins, int currIndex, int amount, vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(currIndex >= coins.size()){
            return 0;
        }
        if(dp[currIndex][amount] != -1){
            return dp[currIndex][amount];
        }
        int consider = 0;
        if(coins[currIndex] <= amount){
            consider = unbounded(coins, currIndex, amount - coins[currIndex], dp);
        }
        int notConsider = unbounded(coins, currIndex + 1, amount, dp);
        return dp[currIndex][amount] = consider + notConsider;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, -1));
        return unbounded(coins, 0, amount, dp);
    }
};