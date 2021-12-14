#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        vector<int> res(0);
        int len = security.size();
        vector<vector<bool>> dp(2, vector<bool>(len, false));
        if (time > len)
        {
            return res;
        }
        if (time == 0)
        {
            for (int i = 0; i < security.size(); i++)
            {
                res.push_back(i);
            }
            return res;
        }
        int count = 0;
        for (int i = 1; i < len; i++)
        {
            if (security[i - 1] >= security[i])
            {
                count++;
            }
            else
            {
                count = 0;
                continue;
            }
            if (count >= time)
            {
                dp[0][i] = true;
            }
        }
        count = 0;
        for (int i = len - 2; i >= 0; i--)
        {
            if (security[i + 1] >= security[i])
            {
                count++;
            }
            else
            {
                count = 0;
                continue;
            }
            if (count >= time)
            {
                dp[1][i] = true;
            }
        }
        for (int i = 0; i < dp[0].size(); i++)
        {
            if (dp[0][i] && dp[1][i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> security = {0,0,0,0};
    vector<int> ans = sol.goodDaysToRobBank(security, 3);
    cout << "End" << endl;
}
/*

Runtime: 124 ms, faster than 88.20% of C++ online submissions for Find Good Days to Rob the Bank.
Memory Usage: 84.3 MB, less than 91.90% of C++ online submissions for Find Good Days to Rob the Bank.

*/