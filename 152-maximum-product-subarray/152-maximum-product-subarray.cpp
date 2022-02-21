class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int>maxVal(n), minVal(n);
        maxVal[0] = nums[0];
        minVal[0] = nums[0];
        for(int i = 1; i < n; i++){
            maxVal[i] = max(maxVal[i-1]*nums[i], max(minVal[i-1]*nums[i], nums[i]));
            minVal[i] = min(maxVal[i-1]*nums[i], min(minVal[i-1]*nums[i], nums[i]));
        }
        int ans = INT_MIN;
        for(auto it : maxVal){
            ans = max(ans, it);
        }
        return ans;
        
    }
};
