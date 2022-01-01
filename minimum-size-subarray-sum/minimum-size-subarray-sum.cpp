class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, res = INT_MAX, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                res = min(res, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res != INT_MAX ? res : 0;
    }
};