class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int currMax = nums[0], currMin = nums[0];
        int ans = currMax;
        for(int i = 1; i < n; i++){
            int temp = currMax;
            currMax = max(temp*nums[i], max(currMin*nums[i], nums[i]));
            currMin = min(temp*nums[i], min(currMin*nums[i], nums[i]));
            ans = max(ans, currMax);
        }
        return ans;
    }
};

// T.C : O(n)  S.C : O(1)