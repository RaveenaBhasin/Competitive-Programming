class Solution {
public:
    int minStep(vector<int>&cost, int currentIndex, unordered_map<int, int>&mp) {
        if(currentIndex == cost.size()){
            return 0;
        } 
        if(currentIndex > cost.size()){
            return 1000;
        }
        int currentKey = currentIndex;
        if(mp.find(currentKey) != mp.end()){
            return mp[currentKey];
        }
        int oneStep = cost[currentIndex] + minStep(cost, currentIndex + 1, mp);
        int twoStep = cost[currentIndex] + minStep(cost, currentIndex + 2, mp);
        mp[currentKey] = min(oneStep, twoStep);
        return min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int>mp;
        int zeroStep = minStep(cost, 0, mp);
        int oneSteps = minStep(cost, 1, mp);
        return min(zeroStep, oneSteps);
    }
};