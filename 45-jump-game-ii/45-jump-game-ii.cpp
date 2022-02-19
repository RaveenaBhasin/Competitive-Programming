class Solution {
public:
    int dp[100001];
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return minJump(nums, 0);
    }
    int minJump(vector<int>&nums, int currentIndex){
        if(currentIndex >= nums.size()-1){
            return 0;
        }
        int ans = 10001;
        int currentKey = currentIndex;
        if(dp[currentKey]!=-1){
            return dp[currentKey];
        }
        int currentJump = nums[currentIndex];
        for(int i = 1; i <= currentJump; i++){
            int tempans = 1 + minJump(nums, currentIndex+i);
            ans = min(ans, tempans);
        }
        dp[currentKey] = ans;
        return ans;
    }
};