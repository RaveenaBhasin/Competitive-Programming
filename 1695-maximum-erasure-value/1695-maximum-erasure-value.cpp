class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, i = 0, j = 0, total = 0;
        unordered_set<int> st;
         for(int i = 0; i < nums.size(); i++) {
            total += nums[i];
            while(st.find(nums[i]) != st.end()) {
                total -= nums[j];
                st.erase(nums[j]);
                j++;
            }
            st.insert(nums[i]);
            ans = max(ans, total);
        }
        return ans;
    }
};

