class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>arr(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());
        int n=nums.size(), s=0, e=n-1;
        while(s<n && nums[s]==arr[s]){
            s++;
        }
        while(e>s && nums[e]==arr[e]){
            e--;
        }
        return e-s+1;
    }
};
