#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution_org
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {    
        if (matrix.empty())
                return 0;
            int row = matrix.size(), col = matrix[0].size(), answer = 0;
            vector<vector<int>> a(row, vector<int>(col)), b(row, vector<int>(col));

            for (int c = 0; c != col; c++)
                for (int r = row - 1, k = 0; r >= 0; r--)
                    if (matrix[r][c] == '1')
                        a[r][c] = ++k;
                    else
                        a[r][c] = k = 0;

            for (int r = 0; r != row; r++)
                for (int c = col - 1, k = 0; c >= 0; c--)
                    if (matrix[r][c] == '1')
                        b[r][c] = ++k;
                    else
                        b[r][c] = k = 0;

            for (int r = 0; r != row; r++)
                for (int c = 0; c != col; c++)
                {
                    int Y = a[r][c];
                    int X = b[r][c];
                    for (int w = c + 1, lim = c + X; w < lim; w++)
                    {
                        //int W = a[r][w];
                        if (Y > a[r][w])
                        {
                            answer = max(answer, min(Y , (w - c)) * min(Y , (w - c)));
                            Y = a[r][w];
                        }
                    }
                    answer = max(answer, min(Y , X) *min(Y , X)) ;
                }

            return answer;
    }
};
/*
ref 0085
Runtime: 28 ms, faster than 43.87% of C++ online submissions for Maximal Square.
Memory Usage: 12.5 MB, less than 5.00% of C++ online submissions for Maximal Square.

*/