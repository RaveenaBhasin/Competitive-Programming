class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size(), m = accounts[0].size();
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                sum += accounts[i][j];
            }
            mx = max(sum, mx);
        }
        return mx;
    }
};