class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans=0, lIndex = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[lIndex]-nums[i]>k){
                ans++;
                lIndex = i;
            }
        }
        return ans+1;
        
    }
};
