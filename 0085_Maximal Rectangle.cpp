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
        {
            return 0;
        }
        //vector<vector<bool>> db(matrix.size()+1,vector<bool>(matrix[0].size()+1,true));
        map<int, vector<vector<int>>> max_rect;
        int m = matrix.size(), n = matrix[0].size();
        int oneCount = 0;
        int Rcount = 0;
        int Ccount = 0;
        int maxR = 0;
        int maxC = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                max_rect[i + j].push_back({i, j, i * j});
                if (matrix[i - 1][j - 1] == '1')
                {
                    oneCount++;
                    Ccount++;
                }
                else
                {
                    Ccount = 0;
                }
                maxC = max(maxC, Ccount);
            }
        }
        for (int c = 0; c < n; c++)
        {
            for (int r = 0; r < m; r++)
            {
                if (matrix[r][c] == '1')
                {
                    Rcount++;
                }
                else
                {
                    Rcount = 0;
                }
                maxR = max(maxR, Rcount);
            }
        }
        int maxArea = 0;
        int recordM = 0;
        int recordN = 0;

        for (int idx = 0; idx < m * n; idx++)
        {
            int _maxArea = 0;
            int idxR = idx / n;
            int idxC = idx % n;
            bool getType = true;
            
            if (matrix[idxR][idxC] == '0')
            {
                continue;
            }
            for (auto aa : max_rect)
            {
                if (!getType)
                {
                    break;
                }
                getType = false;
                for (int mn = 0;mn<aa.second.size();mn++)
                {
                    
                    _maxArea = 0;
                    int maxM = aa.second[mn][0];
                    int maxN = aa.second[mn][1];
                    if (maxM>maxR || maxN>maxC){
                        break;
                    }
                    if(idxR + maxM > m || idxC + maxN > n || maxM * maxN > oneCount)
                    {
                        continue;
                    }
                    for (int aaidx = 0; aaidx < maxM * maxN; aaidx++)
                    {
                        int r = aaidx / maxN + idxR;
                        int c = aaidx % maxN + idxC;
                        if (matrix[r][c] == '0')
                        {
                            _maxArea = 0;
                            break;
                        }
                        _maxArea++;
                    }
                    if (maxM * maxN == _maxArea)
                    {
                        getType = true;
                        //db[maxM][maxN] = false;
                        
                    }
                    //db[idxR][idxC] = max(_maxArea, db[idxR][idxC]);
                    maxArea = max(maxArea,_maxArea);
                    if(maxArea == 147){
                        int x =0;
                    }
                }
            }
            //maxArea = max(maxArea, db[idxR][idxC]);
        }
        return maxArea;
    }
};
class Solution{
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
                            answer = max(answer, Y * (w - c));
                            Y = a[r][w];
                        }
                    }
                    answer = max(answer, Y * X);
                }

            return answer;
        }
};
int main()
{
    Solution sol;
    
    int ans6 = sol.maximalRectangle(matrix7); //6
    printf("end");
}

/*
Input: matrix = {{'1','0','1','0','0'},
                 {'1','0','1','1','1'},
                 {'1','1','1','1','1'},
                 {'1','0','0','1','0'}}
Output: 6

{{'1','1','1','1','1','1','1','1'},
 {'1','1','1','1','1','1','1','0'},
 {'1','1','1','1','1','1','1','0'},
 {'1','1','1','1','1','0','0','0'},
 {'0','1','1','1','1','0','0','0'}}

output:21

{{'1','0','1','1','1'},
{'0','1','0','1','0'},
{'1','1','0','1','1'},
{'1','1','0','1','1'},
{'0','1','1','1','1'}}

Explanation: The maximal rectangle is shown in the above picture.

Constraints:

rows == matrix.length
cols == matrix{i}.length
0 <= row, cols <= 200
matrix{i}{j} is '0' or '1'.

*/