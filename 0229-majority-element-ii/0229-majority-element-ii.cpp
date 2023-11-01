class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        vector<int>res;
        int n = nums.size();
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp) {
            if(it.second > (n/3)) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};