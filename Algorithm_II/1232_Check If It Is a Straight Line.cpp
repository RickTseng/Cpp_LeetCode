#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        double ra = ((double)coordinates[0][0] - coordinates[1][0]) / ((double)coordinates[0][1] - coordinates[1][1]);
        if (coordinates[0][0] == coordinates[1][0])
        {
            ra = 0;
        }
        if (coordinates[0][1] == coordinates[1][1])
        {
            ra = INT_MAX;
        }
        for (int i = 1; i < coordinates.size(); i++)
        {
            double _ra = ((double)coordinates[i - 1][0] - coordinates[i][0]) / ((double)coordinates[i - 1][1] - coordinates[i][1]);
            if (coordinates[i-0][0] == coordinates[i][0])
            {
                _ra = 0;
            }
            if (coordinates[i-0][1] == coordinates[i][1])
            {
                _ra = INT_MAX;
            }

            if (_ra != ra)
            {
                return false;
            }
        }
        return true;
    }
};