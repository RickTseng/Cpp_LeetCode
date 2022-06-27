#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
/**
 * @brief
 * Constraints:

 * n == piles.length
 * 1 <= n <= 1000
 * 1 <= piles[i][j] <= 10^5
 * 1 <= k <= sum(piles[i].length) <= 2000
 */
class Solution
{
public:
    vector<vector<int>> dp;
    int maxValueOfCoins(vector<vector<int>> &piles, int k, int i = 0)
    {
        dp.resize(3,vector<int>(4,0));
        return solve(piles,k);
            
        
        
    }
    int solve(vector<vector<int>> piles,int k,int i = 0)
    {
        if (i == piles.size() || k == 0)
            return 0;
        if (dp[i][k] == 0)
            for (int j = 0, sum = 0; j <= piles[i].size() && k - j >= 0; ++j)
            {
                dp[i][k] = max(dp[i][k], sum + solve(piles, k - j, i + 1));
                if (j < piles[i].size())
                    sum += piles[i][j];
            }
        return dp[i][k];
    }
};
int main()
{
    cout<<"Hello?"<<endl;
    vector<vector<int>> piles = {{1,100,3},{7,8,9}};
    Solution sol;
    int ans = sol.maxValueOfCoins(piles,2);
}