#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), INT_MAX-1));
        for (int r = 0; r < mat.size(); r++)
        {
            for (int c = 0; c < mat[r].size(); c++)
            {
                if (mat[r][c] == 1)
                {
                    if (r > 0)
                    {
                        dp[r][c] = min(dp[r][c], dp[r - 1][c] + 1);
                    }
                    if (c > 0)
                    {
                        dp[r][c] = min(dp[r][c], dp[r][c - 1] + 1);
                    }
                }
                else
                {
                    dp[r][c] = 0;
                }
            }
        }
        for (int r = mat.size() - 1; r >= 0; r--)
        {
            for (int c = mat[r].size() - 1; c >= 0; c--)
            {
                if (r < mat.size() - 1)
                {
                    dp[r][c] = min(dp[r][c], dp[r + 1][c] + 1);
                }
                if (c < mat[r].size() - 1)
                {
                    dp[r][c] = min(dp[r][c], dp[r][c + 1] + 1);
                }
            }
        }
        return dp;
    }
};