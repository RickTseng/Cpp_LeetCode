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
    int maxPoints(vector<vector<int>> &points)
    {
        double deltaTmp = INT_MAX;
        int _max = 1;
        for (int i = 0; i < points.size(); i++)
        {
            double delta = 0;
            for (int j = 0; j < points.size(); j++)
            {
                if (points[i][1] == points[j][1]){
                    delta = INT_MAX;
                }
                else if (points[i][0] == points[j][0]){
                    delta = 0;
                }
                else{
                    delta = ((double)(points[i][0] - points[j][0]) / (double)(points[i][1] - points[j][1]));
                }
                if (j == i || delta == deltaTmp)
                {
                    continue;
                }
                int count = 1;
                for (int jdx = 0; jdx < points.size(); jdx++)
                {
                    double _delta = 0;
                    if(points[i][1] == points[jdx][1]){
                        _delta = INT_MAX;
                    }
                    else if(points[i][0] == points[jdx][0]){
                        _delta = 0;
                    }
                    else{
                        _delta = ((double)(points[i][0] - points[jdx][0]) / (double)(points[i][1] - points[jdx][1]));
                    }
                     
                    if (jdx != i && _delta == delta)
                    {
                        count++;
                        _max = max(_max, count);
                    }
                }
                deltaTmp = delta;
            }
        }
        return _max;
    }
    void worker(vector<vector<int>> points, int idx, double delta, int count)
    {
        if (idx >= points.size())
        {
            return;
        }
    }
};
/**
 * @brief 
[[3,3],[1,4],[1,1],[2,1],[2,2]]
 * 
 * @return int 
 */
int main()
{
    Solution sol;
    vector<vector<int>> points = {{1,0},{0,0}};
    int ans = sol.maxPoints(points);
}