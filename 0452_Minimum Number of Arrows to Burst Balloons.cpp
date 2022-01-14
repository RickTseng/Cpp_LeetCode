#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
class Solution
{
public:
    
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
        {
            return 0;
        }
        sort(points.begin(), points.end(),comp);
        int last = points[0][1];
        int count = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if(points[i][0]>last){
                count++;
                last = points[i][1];
            }
        }

        return count;
    }
};
int main()
{
    vector<vector<int>> point = {{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};
    Solution sol;
    int ans = sol.findMinArrowShots(point);
}
/*

{{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}}

*/