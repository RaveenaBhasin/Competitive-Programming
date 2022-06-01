class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int, int>mp;
        for(auto &it : nums1){
            mp[it]++;
        }
        for(auto &it : nums2){
            if(mp[it] > 0){
                mp[it]--;
                res.push_back(it);
            }
        }
        return res;
    }
};