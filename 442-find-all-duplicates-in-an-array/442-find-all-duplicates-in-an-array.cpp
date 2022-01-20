class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        unordered_map<int, int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        for(auto it : mp){
            if(it.second > 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};