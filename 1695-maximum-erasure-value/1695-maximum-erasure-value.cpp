class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int total = 0, res = 0;
        unordered_map<int, int>mp;
        int i = 0, j = 0, n = nums.size();
        while(j < n){
            total += nums[j];
            while(mp.find(nums[j]) != mp.end()){
                total -= nums[i];
                mp.erase(nums[i]);
                i++;
            }
            mp[nums[j]]++;
            res = max(res, total);
            j++;
        }
        return res;
    }
};
