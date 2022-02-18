class Solution {
public:
    int maxMoney(vector<int>&nums, int currIndex, unordered_map<int, int>&memo){
        if(currIndex >= nums.size()){
            return 0;
        }
        int currKey = currIndex;
        if(memo.find(currKey) != memo.end()){
            return memo[currKey];
        }
        int rob = nums[currIndex] + maxMoney(nums, currIndex + 2, memo);
        int noRob = maxMoney(nums, currIndex + 1, memo);
        memo[currKey] = max(rob, noRob);
        return max(rob, noRob);
    }
    
    int rob(vector<int>& nums) {
        unordered_map<int, int>memo;
        return maxMoney(nums, 0, memo);
    }
};