class Solution {
public:
    int maxPoints(vector<int>&freq, int currIndex, unordered_map<int, int>&mp) {
        if(currIndex >= freq.size()){
            return 0;
        }
        int currKey = currIndex;
        if(mp.find(currKey) != mp.end()){
            return mp[currKey];
        }
        int consider = freq[currKey] + maxPoints(freq, currIndex+2, mp);
        int notConsider = maxPoints(freq, currIndex+1, mp);
        mp[currKey] = max(consider, notConsider);
        return max(consider, notConsider);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>freq(*max_element(nums.begin(), nums.end())+1, 0);
        for(auto it : nums){
            freq[it] += it;
        }
        unordered_map<int, int>mp;
        return maxPoints(freq, 0, mp);
    }
};
