class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, tempSum = 0;
        for(auto it : nums){
            sum += it;
        }
        sum -= x;
        int i = 0, j = 0, res = -1;
        while(j < nums.size() && sum >= 0){
            tempSum += nums[j];
            if(tempSum > sum){
                while(tempSum > sum){
                    tempSum -= nums[i];
                    i++;
                }
            }
            if(tempSum == sum){
                res = max(res,j-i+1);
            }
            j++;  
        }
        if(res != -1)
            res = nums.size()-res;  
        return res;
    }
};