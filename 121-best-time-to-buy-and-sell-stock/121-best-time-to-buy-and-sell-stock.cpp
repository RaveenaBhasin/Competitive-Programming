class Solution {
public: 
    int dp[1000000][2][2];
    int earnedProfit(vector<int>& prices,int day,bool canBuy,int transaction)
    {
        if(day==prices.size() || transaction<=0)
        {
            return 0;
        }
            
        if(dp[day][canBuy][transaction]!=-1) {
                return dp[day][canBuy][transaction];
        }
            
        if(canBuy)
        {
            int idle=earnedProfit(prices,day+1,canBuy,transaction);
            int buying=-prices[day]+earnedProfit(prices,day+1,false,transaction);
            return dp[day][canBuy][transaction] = max(idle,buying);
        }
        else
        {
          int idle=earnedProfit(prices,day+1,canBuy,1);
          int selling=prices[day] + earnedProfit(prices,day+1,true,transaction-1);
          return dp[day][canBuy][transaction] = max(idle,selling);
        }

    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return earnedProfit(prices,0,true,1);
    }
};