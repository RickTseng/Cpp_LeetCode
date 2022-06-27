#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    int matrix[500][500];
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 1;
            }
        }

        for (int i = 0; i < mines.size(); i++)
        {
            matrix[mines[i][0]][mines[i][1]] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1)
                    res = max(res, 1);
                for (int l = 1; l <= n / 2; l++)
                {
                    if (matrix[i][j] == 1 && j - l >= 0 && j + l < n && i - l >= 0 && i + l < n && matrix[i][j + l] == 1 && matrix[i][j - l] == 1 && matrix[i - l][j] == 1 && matrix[i + l][j] == 1)
                    {
                        res = max(res, l + 1);
                    }
                    else
                        break;
                    if (res == l)
                        break;
                }
            }
        }
        return res;
    }
};
/*

Constraints:

1 <= n <= 500
1 <= mines.length <= 5000
0 <= xi, yi < n
All the pairs (xi, yi) are unique.


*/