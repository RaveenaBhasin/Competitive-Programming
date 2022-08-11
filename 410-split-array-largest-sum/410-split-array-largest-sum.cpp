class Solution {
public:
    int isPossible(vector<int>&nums, int mid) {
        int count = 1, currSum = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(currSum + nums[i] <= mid) {
                currSum += nums[i];
            }
            else{
                count++;
                currSum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }
        int mid = 0, ans = 0;
        while(low <= high) {
            mid = low + (high-low)/2;
            int count = isPossible(nums, mid);  //no. of subarrays possible if max sum is mid
            if(count <= m){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};