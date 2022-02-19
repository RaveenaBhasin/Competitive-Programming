class Solution {
public:
    bool isPossible(vector<int>&nums, int currIndex, int dp[10001]){
        if(currIndex >= nums.size()-1){
            return true;
        }
        int currKey = currIndex;
        if(dp[currKey] != -1){
            return dp[currKey];
        }
        int currJump = nums[currIndex];
        bool ans = false;
        for(int i = 1; i <= currJump; i++){
            bool tempAns = isPossible(nums, currIndex + i, dp);
            ans = ans || tempAns;
            if(ans){
                return dp[currKey] = ans;
            }
        }
        return dp[currKey] = false;
    }
    bool canJump(vector<int>& nums) {
        int dp[10001];
        memset(dp, -1, sizeof(dp));
        return isPossible(nums, 0, dp);
    }
};