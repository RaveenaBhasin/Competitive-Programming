class Solution {
public:
    int dp[101][2];
    
    int maxMoney(vector<int>&nums, int cI, int n, bool isValid){
        if(cI >= n){
            return 0;
        }
        if(dp[cI][isValid] != -1){
            return dp[cI][isValid];
        }
        int rob = 0, noRob = 0;
        if(isValid){
            rob = nums[cI] + maxMoney(nums, cI + 2, n, true);
        }
        noRob = maxMoney(nums, cI + 1, n, true);
        return dp[cI][isValid] = max(rob, noRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        memset(dp, -1, sizeof(dp));
        
        int case1 = maxMoney(nums, 0, n-1, true);
        
        memset(dp, -1, sizeof(dp));
    
        int case2 = maxMoney(nums, 1, n, true);
        
        return max(case1, case2);
    }
};