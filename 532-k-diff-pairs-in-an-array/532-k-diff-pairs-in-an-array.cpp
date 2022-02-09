class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(auto it : nums)
        {
            mp[it]++;
        }
        int count = 0;
        if(k == 0){
            for(auto it : mp){
                if(it.second > 1){
                    count++;
                }
            }
        }
        else{
            for(auto it : mp){
                if(mp.find(it.first + k) != mp.end()){
                    count++;
                }
            }
        }
        return count;
    }
};