class Solution {
public:
    //Maintain the min value of stock so far and find the max Profit if sold at the same time
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            //Buy the stock at lower price
            mini = min(mini, prices[i]);
            //Sell the stock at Max price
            maxProfit = max(maxProfit, prices[i] - mini);
        }
        return maxProfit;
    }
};
//T.C : O(n)  S.C : O(1)