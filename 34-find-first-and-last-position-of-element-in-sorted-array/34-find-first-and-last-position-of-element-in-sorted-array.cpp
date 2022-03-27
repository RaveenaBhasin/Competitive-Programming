class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            if(nums[low] < target){
                low++;
            }
            else if(nums[high] > target){
                high--;
            }
            else{
                return {low, high};
            }
        }
        return {-1, -1};
    }
};