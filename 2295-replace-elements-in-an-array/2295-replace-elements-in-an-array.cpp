class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }
        for(auto ele : operations){
            nums[mp[ele[0]]] = ele[1];
            mp[ele[1]] = mp[ele[0]];
        }
        return nums;
    }
};
