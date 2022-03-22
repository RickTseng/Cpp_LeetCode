#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        {
            return -1;
        }
        vector<vector<int>> stepVec = {{0, 0}};
        int count = 1;
        bfs(grid, stepVec,count);
        if(grid[n-1][n-1]==0){
            return -1;
        }
        return count;
    }
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &stepVec,int &count)
    {
        vector<vector<int>> tmpVec;
        int n = grid.size();
        for (auto sv : stepVec)
        {
            int r = sv[0], c = sv[1];
            grid[r][c] = 1;
            if(r==n-1 && c==n-1){
                return;
            }
            if (r > 0 && grid[r - 1][c] != 1)
            {
                
                grid[r - 1][c] = 1;
                tmpVec.push_back({r - 1, c});
            }
            if (r > 0 && c + 1 < n && grid[r - 1][c + 1] != 1)
            {
                
                grid[r - 1][c + 1] = 1;
                tmpVec.push_back({r - 1, c + 1});
            }
            if (c + 1 < n && grid[r][c + 1] != 1)
            {
                
                grid[r][c + 1] = 1;
                tmpVec.push_back({r, c + 1});
            }
            if (r + 1 < n && c + 1 < n && grid[r + 1][c + 1] != 1)
            {
                
                grid[r + 1][c + 1] = 1;
                tmpVec.push_back({r + 1, c + 1});
            }
            if (r + 1 < n && grid[r + 1][c] != 1)
            {
                
                grid[r + 1][c] = 1;
                tmpVec.push_back({r + 1, c});
            }
            if (r + 1 < n && c > 0 && grid[r + 1][c - 1] != 1)
            {
                
                grid[r + 1][c - 1] = 1;
                tmpVec.push_back({r + 1, c - 1});
            }
            if (c > 0 && grid[r][c - 1] != 1)
            {
                
                grid[r][c - 1] = 1;
                tmpVec.push_back({r, c - 1});
            }
            if (r > 0 && c > 0 && grid[r - 1][c - 1] != 1)
            {
                
                grid[r - 1][c - 1] = 1;
                tmpVec.push_back({r - 1, c - 1});
            }
        }
        if(stepVec.empty()){
            return;
        }
        count++;
        bfs(grid,tmpVec,count);
    }

    void dfs(int r, int c, vector<vector<int>> &grid, int count, vector<vector<int>> &tmp)
    {
        if (r >= grid.size() || c >= grid.size() || r < 0 || c < 0)
        {
            return;
        }
        if (grid[r][c] == 1)
        {
            return;
        }
        if (tmp[r][c] != 0 && count > tmp[r][c])
        {
            grid[r][c] = 1;
            return;
        }
        tmp[r][c] = count;
        if (r == grid.size() - 1 && c == grid.size() - 1)
        {
            if (grid[r][c] == -1)
            {
                grid[r][c] = count;
            }
            else
            {
                grid[r][c] = min(grid[r][c], count);
            }
            return;
        }
        grid[r][c] = 1;
        dfs(r - 1, c, grid, count + 1, tmp);
        dfs(r - 1, c + 1, grid, count + 1, tmp);
        dfs(r, c + 1, grid, count + 1, tmp);
        dfs(r + 1, c + 1, grid, count + 1, tmp);
        dfs(r + 1, c, grid, count + 1, tmp);
        dfs(r + 1, c - 1, grid, count + 1, tmp);
        dfs(r, c - 1, grid, count + 1, tmp);
        dfs(r - 1, c - 1, grid, count + 1, tmp);
        grid[r][c] = 0;
    }
};
int main()
{
    /**
     * @brief {{0,1,0,0,1,1,0},{1,0,0,0,0,0,0},{1,0,0,1,1,1,1},{0,1,0,0,0,0,0},{1,0,0,0,0,0,1},{1,0,0,1,0,0,0},{1,0,1,0,0,1,0}}
     *{{0,1,1,0,0,0},{0,1,0,1,1,0},{0,1,1,0,1,0},{0,0,0,1,1,0},{1,1,1,1,1,0},{1,1,1,1,1,0}}
[[0,0,0,0,1],[1,0,0,0,0],[0,1,0,1,0],[0,0,0,1,1],[0,0,0,1,0]]

     */
    //vector<vector<int>> grid = {{0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 1, 1, 1}, {0, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 1, 0}};
    vector<vector<int>> grid = {{0,1,1,0,0,0},{0,1,0,1,1,0},{0,1,1,0,1,0},{0,0,0,1,1,0},{1,1,1,1,1,0},{1,1,1,1,1,0}};
    Solution sol;
    int ans = sol.shortestPathBinaryMatrix(grid);
}