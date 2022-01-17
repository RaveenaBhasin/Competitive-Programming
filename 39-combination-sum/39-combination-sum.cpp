class Solution {
public:
    void totalWays(vector<int>&candidates, int currentIndex, int target, vector<int>&currentAns, vector<vector<int>>&powerSet){
        if(target == 0){
            powerSet.push_back(currentAns);
            return;
        }
        if(currentIndex >= candidates.size()){
            return;
        }
        int currentVal = candidates[currentIndex];
        if(target >= currentVal){
            //Considering the element by appending currentVal in currentAns array
            currentAns.push_back(currentVal);
            totalWays(candidates, currentIndex, target - currentVal, currentAns, powerSet);
            //Not considering
            currentAns.pop_back();
        }
        //Backtracking
        totalWays(candidates, currentIndex + 1, target, currentAns, powerSet);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>powerSet;
        vector<int>possibleSet;
        totalWays(candidates, 0, target, possibleSet, powerSet);
        return powerSet;
    }
};