class Solution {
    void findPerm(vector<int>&nums, int currIndex, vector<vector<int>>&res){
        if(currIndex >= nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int i = currIndex; i < nums.size(); i++){
            if(st.count(nums[i]) > 0){
                continue;
            }
            st.insert(nums[i]);
            swap(nums[currIndex], nums[i]);
            findPerm(nums, currIndex + 1, res);
            swap(nums[currIndex], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        findPerm(nums, 0, res);
        return res;
    }
};


