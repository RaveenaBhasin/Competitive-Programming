class Solution {
public:
    int dp[101][2];

    int maxMoney(vector<int>&nums, int currIndex, int n, bool isValid){
        if(currIndex >= n){
            return 0;
        }
        if(dp[currIndex][isValid] != -1){
            return dp[currIndex][isValid];
        }
        int rob = 0, noRob = 0;
        if(isValid){
            rob = nums[currIndex] + maxMoney(nums, currIndex + 1, n, false);
        }
        noRob = maxMoney(nums, currIndex + 1, n, true);
        return dp[currIndex][isValid] = max(rob, noRob);
    }
    

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]; 
		//when n==1, case1 and case2 return 0 but we have to select the house as there are no adjecent house.
        
        memset(dp,-1,sizeof(dp));
		//case 1: rob from 0...n-1, because all houses are in circular so nth is adjecent to 0th house
        int case1 = maxMoney(nums, 0, n-1, true);
		
        memset(dp,-1,sizeof(dp));
		//case 2: rob from 1...n,
        int case2 = maxMoney(nums,1, n, true);
		
		//return maximum between case1 & case2
        return max(case1,case2);
    }
};