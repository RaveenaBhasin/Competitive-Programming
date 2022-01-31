class Solution {
public:
    int possibleCombo(vector<int>&nums, int currIndex, int target, unordered_map<int, int>&mp) {
        if(target == 0){
            return 1;
        }
        if(currIndex >= nums.size()){
            return 0;
        }
        int currKey = target;
        if(mp.find(currKey) != mp.end()){
            return mp[currKey];
        }
        int consider = 0; 
        if(nums[currIndex] <= target){
            consider = possibleCombo(nums, 0, target - nums[currIndex], mp);
        }
        int notConsider = possibleCombo(nums, currIndex + 1, target, mp);
        return mp[currKey] = consider + notConsider;
    }
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        return possibleCombo(nums, 0, target, mp);
    }
};