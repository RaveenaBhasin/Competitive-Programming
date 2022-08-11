class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int len = 2;
        vector<unordered_map<int, int>>dp(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int diff = nums[j] - nums[i];
                if(dp[i].find(diff) != dp[i].end()) {
                    dp[j][diff] = dp[i][diff] + 1;
                }
                else{
                    dp[j][diff] = 2;
                }
                len = max(len, dp[j][diff]);
            }
        }
        return len;
    }
};

