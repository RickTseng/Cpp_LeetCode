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
// Runtime: 179 ms, faster than 38.28% of C++ online submissions for Island Perimeter.
// Memory Usage: 96.2 MB, less than 84.53% of C++ online submissions for Island Perimeter.
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(),n = grid[0].size();
        for(int r = 0;r<m;++r)
        {
            for(int c = 0;c<n;++c)
            {
                if(grid[r][c]!=1)
                {
                    continue;
                }
                count+=4;
                //up
                if(r > 0 && grid[r-1][c] == 1)
                {
                    count--;
                }
                //down
                if(r + 1 < m && grid[r+1][c] == 1)
                {
                    count--;
                }
                //left
                if(c > 0 && grid[r][c-1] == 1)
                {
                    count--;
                }
                //right
                if(c + 1 < n && grid[r][c+1] == 1)
                {
                    count--;
                }
            }
        }
        return count;
    }
};