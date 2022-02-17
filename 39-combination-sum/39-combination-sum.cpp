class Solution {
public:
    void totalWays(vector<int>&candidates, int currIndex, int target, vector<int>&currAns, vector<vector<int>>&powerSet){
        if(target == 0){
            powerSet.push_back(currAns);
            return;
        }
        if(currIndex >= candidates.size()){
            return;
        }
        int currVal = candidates[currIndex];
        if(target >= currVal){
            currAns.push_back(currVal);
            totalWays(candidates, currIndex, target - currVal, currAns, powerSet);
            currAns.pop_back();
        }
        totalWays(candidates, currIndex + 1, target, currAns, powerSet);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>powerSet;
        vector<int>aux;
        totalWays(candidates, 0, target, aux, powerSet);
        return powerSet;
    }
};