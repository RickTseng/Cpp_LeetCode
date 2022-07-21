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

// Runtime: 6 ms, faster than 11.73% of C++ online submissions for Spiral Matrix.
// Memory Usage: 7.3 MB, less than 30.29% of C++ online submissions for Spiral Matrix.

class Solution
{
public:
    vector<int> res;
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(),n = matrix[0].size();
        readMatrix(matrix,m,n,0,0,"R");
        return res;
    }
    void readMatrix(vector<vector<int>> &matrix, int m, int n, int r, int c, string side)
    {
        if(res.size()==m*n) return;
        res.push_back(matrix[r][c]);
        matrix[r][c] = INT_MAX;
        if (side == "R")
        {

            if (c + 1 == n || matrix[r][c + 1] == INT_MAX)
            {
                readMatrix(matrix, m, n, r + 1, c, "D");
            }
            else
            {
                readMatrix(matrix, m, n, r, c + 1, "R");
            }
        }
        if (side == "D")
        {
            if (r + 1 == m || matrix[r + 1][c] == INT_MAX)
            {
                readMatrix(matrix, m, n, r, c - 1, "L");
            }
            else
            {
                readMatrix(matrix, m, n, r + 1, c, "D");
            }
        }
        if (side == "L")
        {
            if (c - 1 < 0 || matrix[r][c - 1] == INT_MAX)
            {
                readMatrix(matrix, m, n, r - 1, c, "U");
            }
            else
            {
                readMatrix(matrix, m, n, r, c - 1, "L");
            }
        }
        if (side == "U")
        {
            if (r - 1 < 0 || matrix[r - 1][c] == INT_MAX)
            {
                readMatrix(matrix, m, n, r, c + 1, "R");
            }
            else
            {
                readMatrix(matrix, m, n, r - 1, c, "U");
            }
        }
    }
};
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    vector<int> ans = sol.spiralOrder(matrix);
}
