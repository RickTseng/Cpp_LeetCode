#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Solution
{
public:
    int maxProfit_RefWeb(vector<int> &prices)
    {
        if (prices.size() == 1)
        {
            return 0;
        }
        if (prices.size() == 2)
        {
            if (prices[0] >= prices[1])
            {
                return 0;
            }
        }
        int income = 0;
        int rest = 0;
        int hold = INT_MIN;
        for (auto p : prices)
        {
            int pre_income = income;
            income = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, pre_income);
        }
        return max(hold, income);
    }
    void dfs(vector<int> &dp, vector<int> prices, int index, int incon, int buyP)
    {
        if (index > prices.size())
        {
            return;
        }
        if (prices[index] - buyP > dp[index])
        {
            dp[index] = max(dp[index], incon + prices[index] - buyP);
            incon += prices[index] - buyP;
            dfs(dp, prices, index + 3, incon, prices[index + 2]);
        }
        else
        {
            //dp[index] = incon;
            dfs(dp, prices, index + 1, incon, buyP);
        }
    }
    
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for (int price : prices)
        {
            pre_buy = buy;
            buy = max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }
        return sell;


        
    }
};
class Solution_Ref_Web{
public:
    int maxProfit_2(vector<int> &prices)
    {
        if (prices.size() == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (i == 1)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            }
            else
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            }
        }
        return dp[prices.size() - 1][0];
    }
    int maxProfit_3(vector<int> &prices){
        int nostock=0,buy=-prices[0],sell=0,t=0;
        for(int i=1;i<prices.size();i++){
            t=max(buy,nostock-prices[i]);
            nostock=max(nostock,sell);
            sell=buy+prices[i];
            buy=t;
        }
        return max(sell,nostock);
    }
};
int main()
{
    //vector<int> prices = {1,2,4};
    vector<int> prices = {1, 2, 3, 0, 2};
    //vector<int> prices(5000,1000);
    /*vector<int> prices;
    for(int i = 0;i<5000;i++){
        prices.push_back(i+1);
    }
    */
    Solution sol;
    int ans = sol.maxProfit(prices);
}
/*
1 <= prices.length <= 5000
0 <= prices[i] <= 1000

[1,2,3,0,2]
ans:3
*/