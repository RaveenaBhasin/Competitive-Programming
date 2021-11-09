class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int curr_len = 1, longest = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i] == nums[i-1]+1){
                curr_len++;
            }
            else{
                longest = max(longest, curr_len);
                curr_len = 1;
            }
        }
        return max(longest, curr_len);
    }
};

// T.C : O(nlogn)  S.C : O(1)