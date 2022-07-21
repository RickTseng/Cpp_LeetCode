#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <set>
#include <unordered_set>

// Runtime: 138 ms, faster than 5.03% of C++ online submissions for Course Schedule II.
// Memory Usage: 33.4 MB, less than 5.18% of C++ online submissions for Course Schedule II.

using namespace std;
class Solution
{
public:
    vector<int> res,finishTb;
    int _max;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> rc(numCourses, vector<int>());
        vector<int> sourceTb(numCourses, 0);
        finishTb.resize(numCourses, 0);
        if(numCourses>1){
            _max = numCourses * (numCourses-1);
        }
        else{
            _max = 1;
        }
        for (auto condition : prerequisites)
        {
            int des = condition[0];
            int sou = condition[1];
            rc[sou].push_back(des);
            if(!rc[des].empty() && find(begin(rc[des]),end(rc[des]),sou)!=end(rc[des]))
            {
                return res;
            }
            sourceTb[des]++;
        }
        bool looped = false;
        int size = 0;
        for (int idx = 0; idx < numCourses; ++idx)
        {
            isLoop(rc, idx, idx, looped,0);
            if (looped)
            {
                return {};
            }
            if (sourceTb[idx] == 0)
            {
                dfs(rc, idx);
            }
        }
        
        return res;
    }
    void isLoop(vector<vector<int>> &rc,int target,int cur, bool &looped,int count)
    {
        if(count>=_max)
        {
            looped = true;
            return;
        }
        for(int jdx = 0;jdx<rc[cur].size();++jdx)
        {      
            if(rc[cur][jdx]==target)
            {   
                looped = true;
                return;
            }
            if(!looped)
            {
                isLoop(rc,target,rc[cur][jdx],looped,count+1);  
            }                      
        }
    }
    void dfs(vector<vector<int>> &rc, int idx)
    {
        finishTb[idx]++;
        for(int jdx = 0;jdx<rc[idx].size();++jdx)
        {      
            if(finishTb[rc[idx][jdx]]==0)
            {
                dfs(rc, rc[idx][jdx]);
            }                 
        }
        res.insert(begin(res), idx);
        
        //finishTb[idx] = 1; 
    }
};
int main()
{
    // 22/44 pass
    // vector<vector<int>> prerequisites = {
    //     {7, 0}, {8, 0}, {1, 7}, {2, 8}, {3, 7}, {3, 8}, {4, 1}, {4, 2}, {5, 3}, {5, 4}, {6, 5}};
    // 4 {{0,1},{0,2},{1,3},{3,0}}; ans = []
//     //4
//     {{1,0},{2,1},{3,2},{1,3}};
    //  {{0,1},{0,2},{1,2}};
    Solution sol;
    vector<vector<int>> prerequisites = {{1,0},{2,1},{3,2},{1,3}};
    //vector<vector<int>> prerequisites = {{7, 0}, {8, 0}, {1, 7}, {2, 8}, {3, 7}, {3, 8}, {4, 1}, {4, 2}, {5, 3}, {5, 4}, {6, 5}};
    vector<int> ans = sol.findOrder(4, prerequisites);
}

/*

[[7,0],[8,0],[1,7],[2,8],[3,7],[3,8],[4,1],[4,2],[5,3],[5,4],[6,5]]
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