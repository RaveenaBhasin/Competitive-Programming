class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        return mn;
    }
};