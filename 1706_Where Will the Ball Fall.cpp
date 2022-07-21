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

// Runtime: 37 ms, faster than 55.08% of C++ online submissions for Where Will the Ball Fall.
// Memory Usage: 14.3 MB, less than 7.23% of C++ online submissions for Where Will the Ball Fall.

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<int> tmp(n,-1);
        grid.insert(begin(grid),tmp);
        vector<vector<int>> dp(m + 1,vector<int>(n,-1));
        for(int i = 0;i<n;++i){
            dp[0][i] = i;
        }
        for(int r = 1; r < m+1; ++r){
            for(int c = 0;c < n; ++c)
            {
                if(dp[r-1][c]!=-1)
                {
                    
                    if(grid[r][c] == 1)
                    {
                        if(c+1<n && grid[r][c+1] == 1)
                        {
                            dp[r][c+1] = dp[r-1][c];
                            //tmp[dp[r-1][c]] = c+1;
                        }
                    }
                    if(grid[r][c]== -1 )
                    {
                        if(c>0 && grid[r][c-1] == -1)
                        {
                            dp[r][c-1] = dp[r-1][c];
                            //tmp[dp[r-1][c]] = c-1;
                        }
                    }
                }
            }
        }
        for(int idx = 0;idx<dp.back().size();++idx)
        {
            if(dp.back()[idx] != -1){
                tmp[dp.back()[idx]] = idx;
            }
            
        }
        return tmp;
    }
};
int main(){
    vector<vector<int>> grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    Solution sol;
    vector<int> ans = sol.findBall(grid);
}