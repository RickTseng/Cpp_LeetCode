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

// Runtime: 63 ms, faster than 33.33% of C++ online submissions for Check if Matrix Is X-Matrix.
// Memory Usage: 16.4 MB, less than 33.33% of C++ online submissions for Check if Matrix Is X-Matrix.


class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n && i<(n+1)/2; ++i)
        {
            if (grid[i][i] == 0 || grid[i][n - i - 1] == 0 || grid[n - i - 1][n - i - 1] == 0 || grid[n - i - 1][i] == 0)
            {
                return false;
            }
            for (int j = i + 1; j < n && j<(n+1)/2; ++j)
            {
                if (grid[i][j] != 0 || grid[i][n - j - 1] != 0 || grid[n - i - 1][n - j - 1] != 0 || grid[n - i - 1][j] != 0 || grid[j][i] != 0 || grid[n - j - 1][i] != 0 || grid[j][n - i - 1] != 0 || grid[n - j - 1][n - i - 1] != 0

                )
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    cout<<"Hello"<<endl;
    vector<vector<int>> grid = {{2, 0, 0, 1}, {0, 3, 1, 0}, {0, 5, 2, 0}, {4, 0, 0, 2}};
    cout<<"Hello"<<endl;
    Solution sol;
    cout<<"Hello"<<endl;
    bool ans = sol.checkXMatrix(grid);
}
// Constraints:

// n == grid.length == grid[i].length
// 3 <= n <= 100
// 0 <= grid[i][j] <= 10^5