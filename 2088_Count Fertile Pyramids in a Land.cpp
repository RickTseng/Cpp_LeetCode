#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    int countPyramids(vector<vector<int>> &grid)
    {
        if (grid.size() == 1 || grid[0].size() == 1)
        {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> _countD(m, vector<int>(n, 0));
        vector<vector<int>> _countU(m, vector<int>(n, 0));
        vector<vector<int>> _right(m, vector<int>(n, 0));
        vector<vector<int>> _left(m, vector<int>(n, 0));
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (c == 0)
                {
                    _right[r][c] = grid[r][c];
                }
                else if (grid[r][c] != 0)
                {
                    _right[r][c] = _right[r][c - 1] + 1;
                }
            }
            for (int c = n - 1; c >= 0; c--)
            {
                if (c == n - 1)
                {
                    _left[r][c] = grid[r][c];
                }
                else if (grid[r][c] != 0)
                {
                    _left[r][c] = _left[r][c + 1] + 1;
                }
            }
        }
        //***
        // *
        int _sum = 0;
        for (int r = 1; r < m; r++)
        {
            for (int c = 1; c < n - 1; c++)
            {
                if (grid[r][c] && _right[r - 1][c + 1] >= 3 && _left[r - 1][c - 1] >= 3)
                {
                    if (_countD[r - 1][c - 1] && _countD[r - 1][c + 1])
                    {
                        _countD[r][c] = min(_countD[r - 1][c - 1], _countD[r - 1][c + 1]) + 1;
                    }
                    else
                    {
                        _countD[r][c] += 1;
                    }
                    _sum +=_countD[r][c];
                }
            }
        }
        // *
        //***
        for (int r = m - 2; r >= 0; r--)
        {
            for (int c = 1; c < n - 1; c++)
            {
                if (grid[r][c] && _right[r + 1][c + 1] >= 3 && _left[r + 1][c - 1] >= 3)
                {
                    if (_countU[r + 1][c - 1] && _countU[r + 1][c + 1])
                    {
                        _countU[r][c] = min(_countU[r + 1][c - 1], _countU[r + 1][c + 1]) + 1;
                    }
                    else
                    {
                        _countU[r][c] += 1;
                    }
                    _sum +=_countU[r][c];
                }
            }
        }
        
        return _sum;
    }
};
int main()
{
    vector<vector<int>> grid0 = {
        {1 ,1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 1}};
    vector<vector<int>> grid(1000, vector<int>(100, 1));
    Solution sol;
    int ans = sol.countPyramids(grid0);
}
/*

Input: grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
Output: 13


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 10^5
grid[i][j] is either 0 or 1.

*/