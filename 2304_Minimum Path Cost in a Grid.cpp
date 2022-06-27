#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) 
    {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dp[0] = grid[0];
        for(int r = 1;r<grid.size();r++)
        {
            for(int c = 0;c<grid[r].size();c++)
            {
                for(int k = 0;k<grid[r].size();k++)
                {
                    dp[r][k] = min(dp[r][k],grid[r][k] + dp[r - 1][c] + moveCost[grid[r - 1][c]][k]);
                }
            }
        }
        return *min_element(begin(dp[grid.size()-1]),end(dp[grid.size()-1]));
    }
};