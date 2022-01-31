class Solution {
public:
    int unbounded(vector<int>&coins, int currIndex, int amount, vector<vector<int>>&dp) {
        if(amount == 0){
            return 0;
        }
        if(currIndex >= coins.size()){
            return 100000;
        }
        if(dp[currIndex][amount] != -1){
            return dp[currIndex][amount];
        }
        int consider = 100000;
        if(coins[currIndex] <= amount){
            consider = 1 + unbounded(coins, currIndex, amount - coins[currIndex], dp);
        }
        int notConsider = unbounded(coins, currIndex + 1, amount, dp);
        return dp[currIndex][amount] = min(consider, notConsider);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = unbounded(coins, 0, amount, dp);
        if(ans == 100000){
            return -1;
        }
        else{
            return ans;
        }
    }
};