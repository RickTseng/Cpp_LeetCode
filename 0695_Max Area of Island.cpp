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
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int _max = 0;
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[r].size(); c++)
            {
                int count = 0;
                dfs(grid, r, c, _max, count);
            }
        }
        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[r].size(); c++)
            {
                cout<<grid[r][c]<<ends;
                
            }
            cout<<endl;
        }
        
        return _max;
    }
    void dfs(vector<vector<int>> &grid, int r, int c, int &_max, int &count)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size())
        {
            return;
        }
        if (grid[r][c] != 1)
        {
            return;
        }
        count++;
        grid[r][c] = 2;
        _max = max(_max, count);
        dfs(grid, r - 1, c, _max, count);
        dfs(grid, r + 1, c, _max, count);
        dfs(grid, r, c - 1, _max, count);
        dfs(grid, r, c + 1, _max, count);
    }
};
int main()
{
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
        };
    Solution sol;
    int ans = sol.maxAreaOfIsland(grid);
}
/**
 * @brief
 * Runtime: 30 ms, faster than 37.82% of C++ online submissions for Max Area of Island.
 * Memory Usage: 23.4 MB, less than 52.33% of C++ online submissions for Max Area of Island.
 * 
 */
