#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    long long mostPoints_o(vector<vector<int>> &questions)
    {
        long long _max = 0;
        if (questions.size() == 1)
        {
            return questions[0][0];
        }
        vector<long long> rc(questions.size(), -1);
        for (int i = 0; i < questions.size(); i++)
        {

            long long count = 0;

            count += questions[i][0];
            rc[i] = count;
            _max = max(_max, count);
            dfs(questions, _max, count, rc, i + questions[i][1] + 1);
        }
        return _max;
    }
    void dfs(vector<vector<int>> questions, long long &_max, long long count, vector<long long> &rc, int idx)
    {
        if (idx >= questions.size())
        {
            return;
        }

        for (int jdx = idx; jdx < questions.size(); jdx++)
        {
            if (count + questions[jdx][0] <= rc[jdx])
            {
                continue;
            }
            dfs(questions, _max, count + questions[jdx][0], rc, jdx + questions[jdx][1] + 1);
            _max = max(_max, count + questions[jdx][0]);
            rc[jdx] = max(_max, rc[jdx]);
        }
    }
    long long mostPoints(vector<vector<int>> &q)
    {
        vector<long long> dp(q.size(), 0);
        for (int i = q.size() - 1; i >= 0; i--)
        {
            if (i + q[i][1] + 1 < q.size())
                dp[i] = max(q[i][0] + dp[i + q[i][1] + 1], dp[i + 1]);
            else if (i + 1 < q.size())
                dp[i] = max((long long)q[i][0], dp[i + 1]);
            else
                dp[i] = max(dp[i], (long long)q[i][0]);
        }
        return dp[0];
    }
};
int main()
{
    vector<vector<int>> questions = {{21,2},{1,2},{12,5},{7,2},{35,3},{32,2},{80,2},{91,5},{92,3},{27,3},{19,1},{37,3},{85,2},{33,4},{25,1},{91,4},{44,3},{93,3},{65,4},{82,3},{85,5},{81,3},{29,2},{25,1},{74,2},{58,1},{85,1},{84,2},{27,2},{47,5},{48,4},{3,2},{44,3},{60,5},{19,2},{9,4},{29,5},{15,3},{1,3},{60,2},{63,3},{79,3},{19,1},{7,1},{35,1},{55,4},{1,4},{41,1},{58,5}};
    Solution sol;
    long long ans = sol.mostPoints(questions);
}
/*
{{21,2},{1,2},{12,5},{7,2},{35,3},{32,2},{80,2},{91,5},{92,3},{27,3},{19,1},{37,3},{85,2},{33,4},{25,1},{91,4},{44,3},{93,3},{65,4},{82,3},{85,5},{81,3},{29,2},{25,1},{74,2},{58,1},{85,1},{84,2},{27,2},{47,5},{48,4},{3,2},{44,3},{60,5},{19,2},{9,4},{29,5},{15,3},{1,3},{60,2},{63,3},{79,3},{19,1},{7,1},{35,1},{55,4},{1,4},{41,1},{58,5}}



*/