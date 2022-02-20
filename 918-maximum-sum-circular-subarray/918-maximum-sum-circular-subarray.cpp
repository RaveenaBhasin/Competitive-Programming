class Solution {
public:
    // kadane's algorithm
    int maxsum(vector<int> &nums, int n)
    {
        int max_end = nums[0], res = nums[0];
        for(int i = 1; i < n; i++)
        {
            max_end = max(max_end + nums[i], nums[i]);
            res = max(res, max_end);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_normal = INT_MIN, max_circular = INT_MIN, sum = 0;
        int n = nums.size();

        max_normal = maxsum(nums, n);// max subarray sum of normal array 
        if(max_normal < 0)return max_normal;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i]; // total sum of normal array
            nums[i] = -nums[i];// inverting normal array
        }
        max_circular = maxsum(nums, n);// max subarray sum of inverted array
        
        return max(max_circular + sum, max_normal);
    }
};