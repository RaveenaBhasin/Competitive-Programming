class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minProfit = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            int currProfit = prices[i] - minProfit;
            maxProfit = max(currProfit, maxProfit);
            minProfit = min(prices[i], minProfit);
        }
        return maxProfit;
    }
};

