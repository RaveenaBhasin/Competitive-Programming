class Solution {
public:
    void generateAllSubsets(vector<int>&nums, int currentIndex, vector<int>&res, vector<vector<int>>&powerSet){
        //Base condition
        //Once index is greater than or equal to size store it in result
        if(currentIndex >= nums.size()){
            powerSet.push_back(res);
            return;
        }
        int currentVal = nums[currentIndex];
        res.push_back(currentVal);
        generateAllSubsets(nums, currentIndex + 1, res, powerSet);
        //Remove the currentVal(not considering)
        res.pop_back();
        generateAllSubsets(nums, currentIndex + 1, res, powerSet);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>powerSet;
        vector<int>res;
        generateAllSubsets(nums, 0, res, powerSet);
        return powerSet;
    }
};