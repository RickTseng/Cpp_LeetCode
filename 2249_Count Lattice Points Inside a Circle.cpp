#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/**
 * @brief Constraints:

1 <= circles.length <= 200
circles[i].length == 3
1 <= xi, yi <= 100
1 <= ri <= min(xi, yi)
 *
 */

class Solution
{
public:
    int countLatticePoints(vector<vector<int>> &circles)
    {
        vector<vector<bool>> mp(201, vector<bool>(201, false));
        int res = 0;
        for (auto circle : circles)
        {
            int x = circle[0];
            int y = circle[1];
            int r = circle[2];
            if(!mp[x][y])
            {
                mp[x][y] = true;
                res++;
            }
            for (int xr = 0; xr <= r; xr++)
            {
                for (int yr = 0; yr <= r; yr++)
                {
                    if ((xr * xr) + (yr * yr) <= r * r)
                    {
                        if (!mp[x + xr][y + yr])
                        {
                            mp[x + xr][y + yr] = true;
                            res++;
                        }
                        if (!mp[x - xr][y + yr])
                        {
                            mp[x - xr][y + yr] = true;
                            res++;
                        }
                        if (!mp[x + xr][y - yr])
                        {
                            mp[x + xr][y - yr] = true;
                            res++;
                        }
                        if (!mp[x - xr][y - yr])
                        {
                            mp[x - xr][y - yr] = true;
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};
int main(){
    vector<vector<int>> circles = {{2,2,2},{3,4,1}};
    Solution sol;
    int ans = sol.countLatticePoints(circles);
}