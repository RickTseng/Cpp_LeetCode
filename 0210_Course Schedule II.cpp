#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        //vector<vector<int>> db(1);
        vector<int> db;
        vector<int> res;
        if (prerequisites.empty())
        {
            res.clear();
            for (int i = numCourses - 1; i >= 0; i--)
            {
                res.push_back(i);
            }
            return res;
        }
        vector<bool> base0(numCourses);
        for (auto p : prerequisites)
        {
            base0[p[0]] = true;
        }
        for (int i = 0; i < base0.size(); i++)
        {
            if (!base0[i])
            {
                db.push_back(i);
                res.push_back(i);
            }
        }
        if(db.empty()){
            return res;
        }
        while (res.size() < numCourses)
        {
            vector<int> tmp1;
            for (int idx = 0; idx < db.size(); idx++)
            {
                int i = 0;
                while (i < prerequisites.size())
                {
                    if (prerequisites[i][1] == db[idx])
                    {
                        if (find(tmp1.begin(), tmp1.end(), prerequisites[i][0]) == tmp1.end())
                        {
                            tmp1.push_back(prerequisites[i][0]);
                        }
                        if (find(res.begin(), res.end(), prerequisites[i][0]) == res.end())
                        {
                            res.push_back(prerequisites[i][0]);
                        }
                        prerequisites.erase(prerequisites.begin() + i, prerequisites.begin() + i + 1);
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            db = tmp1;
        }

        return res;
    }
};
int main()
{
    //22/44 pass
    //vector<vector<int>> prerequisites = {
    //    {7, 0}, {8, 0}, {1, 7}, {2, 8}, {3, 7}, {3, 8}, {4, 1}, {4, 2}, {5, 3}, {5, 4}, {6, 5}};
    Solution sol;
    vector<vector<int>> prerequisites = {{0,1},{0,2},{1,2}};
    vector<int> ans = sol.findOrder(3, prerequisites);
}

/*

{{7,0},{8,0},{1,7},{2,8},{3,7},{3,8},{4,1},{4,2},{5,3},{5,4},{6,5}}
9

[0,8,2,7,3,1,4,5,6}


Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i}.length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi} are distinct.


*/