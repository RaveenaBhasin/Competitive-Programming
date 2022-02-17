class Solution {
public:
    int totalWays(int currStair, int target, unordered_map<int, int>&memo) {
        if(currStair == target){
            return 1;
        }
        if(currStair > target){
            return 0;
        }
        int currKey = currStair;
        if(memo.find(currKey) != memo.end()) {
            return memo[currKey];
        }
        int oneStep = totalWays(currStair + 1, target, memo);
        int twoSteps = totalWays(currStair + 2, target, memo);
        memo[currKey] = oneStep + twoSteps;
        return oneStep + twoSteps;
    }
    int climbStairs(int n) {
        unordered_map<int, int>memo;
        return totalWays(0, n, memo);
    }
};