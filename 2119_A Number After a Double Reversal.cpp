#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isSameAfterReversals(int num)
    {
        if (num < 10)
        {
            return true;
        }
        if (num % 10 == 0)
        {
            return false;
        }
        return true;
    }
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            int r = startPos[0];
            int c = startPos[1];
            int len = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (c + 1 < n && s[j] == 'R')
                {
                    c += 1;
                    len++;
                }
                else if (c - 1 >= 0 && s[j] == 'L')
                {
                    c -= 1;
                    len++;
                }
                else if (r - 1 >= 0 && s[j] == 'U')
                {
                    r -= 1;
                    len++;
                }
                else if (r + 1 < n && s[j] == 'D')
                {
                    r += 1;
                    len++;
                }
                else
                {
                    //res.push_back(len);
                    break;
                }
            }
            res.push_back(len);
        }
        return res;
    }
};
int main()
{
    vector<int> startPos = {0, 1};
    Solution sol;
    vector<int> ans = sol.executeInstructions(3, startPos, "RRDDLU");
}
/*
Input: n = 3, startPos = [0,1], s = "RRDDLU"
Output: [1,5,4,3,1,0]

Constraints:

m == s.length
1 <= n, m <= 500
startPos.length == 2
0 <= startrow, startcol < n
s consists of 'L', 'R', 'U', and 'D'.

*/