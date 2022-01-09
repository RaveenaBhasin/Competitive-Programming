class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> v;
        for(auto &i : nums){
            v.push_back(1-i);
        }
        return min(getSwaps(nums), getSwaps(v));
    }
    
    int getSwaps(vector<int>& nums){
        int ones = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) ones++;
        }
        int x = ones;
        int cnt1 = 0, max1;
        for(int i = 0; i < x; i++){
            if(nums[i] == 1) cnt1++;
        }

        max1 = cnt1;

        for (int i = 1; i <= n-x; i++) {
            if (nums[i-1] == 1) cnt1--;
            if(nums[i+x-1] == 1) cnt1++;
            if (max1 < cnt1) max1 = cnt1;
        }
        return x - max1;
    }
};