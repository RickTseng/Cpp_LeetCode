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
    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX - 1));
        vector<pair<int, int>> rec;
        int _max = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[r].size(); c++)
            {
                if (grid[r][c] == 2)
                {
                    dp[r][c] = 0;
                    rec.emplace_back(r, c);
                }
            }
        }
        while (!rec.empty())
        {
            vector<pair<int, int>> rec1;
            for (auto rc : rec)
            {
                int r = rc.first, c = rc.second;
                if (r > 0 && grid[r - 1][c] == 1)
                {
                    dp[r - 1][c] = min(dp[r - 1][c], dp[r][c] + 1);
                    grid[r - 1][c] = 2;
                    _max = max(_max,dp[r-1][c]);
                    rec1.emplace_back(r - 1, c);
                }
                if (c > 0 && grid[r][c - 1] == 1)
                {
                    dp[r][c - 1] = min(dp[r][c - 1], dp[r][c] + 1);
                    grid[r][c - 1] = 2;
                    _max = max(_max,dp[r][c-1]);
                    rec1.emplace_back(r, c - 1);
                }
                if (r + 1 < grid.size() && grid[r + 1][c] == 1)
                {
                    dp[r + 1][c] = min(dp[r + 1][c], dp[r][c] + 1);
                    grid[r + 1][c] = 2;
                    _max = max(_max,dp[r+1][c]);
                    rec1.emplace_back(r + 1, c);
                }
                if (c + 1 < grid[r].size() && grid[r][c + 1] == 1)
                {
                    dp[r][c + 1] = min(dp[r][c + 1], dp[r][c] + 1);
                    grid[r][c + 1] = 2;
                    _max = max(_max,dp[r][c+1]);
                    rec1.emplace_back(r, c + 1);
                }
            }
            rec = rec1;
        }

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[r].size(); c++)
            {
                if (grid[r][c] == 1)
                {
                    return -1;
                }
            }
        }
        return _max;
    }
};
int main()
{
    vector<vector<int>> mat = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 2}};
    Solution sol;
    int ans = sol.orangesRotting(mat);
}
/**
 * @brief 
 * Runtime: 19 ms, faster than 13.05% of C++ online submissions for Rotting Oranges.
 * Memory Usage: 13.5 MB, less than 22.16% of C++ online submissions for Rotting Oranges.
 * 
 */