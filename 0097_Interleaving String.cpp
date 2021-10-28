#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
class Solution_v1
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1 == "" && s2 == "" && s3 == "")
        {
            return true;
        }
        if (s1 == "" && s2 == s3)
        {
            return true;
        }
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        bool res = false;
        int index = 0;
        int s2index = 0;
        string tmp = "";
        for (int index = 0; index < s3.size(); index++)
        {
            dp(tmp, index, 0, s1, s2, s3, res);
            if (res)
            {
                return true;
            }
            else
            {
                tmp += s3[index];
            }
        }
        return false;
    }
    void dp(string tmp, int index, int s2index, string s1, string s2, string s3, bool &res)
    {
        if (tmp != "" && s2index >= s2.size() && tmp == s1)
        {
            res = true;
            return;
        }
        if (index >= s3.size())
        {
            return;
        }
        if (s2index < s2.size() && s3[index] == s2[s2index])
        {
            s2index += 1;
        }
        else
        {
            tmp += s3[index];
        }
        dp(tmp, index + 1, s2index, s1, s2, s3, res);
    }
};
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size();
        int m = s2.size();
        if (s3.size() != n + m)
        {
            return false;
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        s3 = ' ' + s3;
        for (int r = 0; r <= n; r++)
        {
            for (int c = 0; c <= m; c++)
            {
                if (!r && !c)
                {
                    dp[r][c] = true;
                }
                else
                {
                    if (r && s1[r] == s3[r + c])
                    {
                        dp[r][c] = dp[r - 1][c];
                    }
                    if (c && s2[c] == s3[r + c])
                    {
                        dp[r][c] = dp[r][c] || dp[r][c - 1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    bool ans1 = sol.isInterleave("aabc", "abad", "aabcabad");
    bool ans2 = sol.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    bool ans3 = sol.isInterleave("aabc", "abad", "aabacbad");
    bool ans4 = sol.isInterleave("aabcc", "dbbca", "aadbcbbcac");
    printf("00");
}
/*
 s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 0 <= s1.length, s2.length <= 100
 0 <= s3.length <= 200
 s1, s2, and s3 consist of lowercase English letters.

 Follow up: Could you solve it using only O(s2.length) additional memory space?

"aabc"
"abad"
"aabcabad"

"aabcc"
"dbbca"
"aadbcbbcac"


Runtime: 0 ms, faster than 100.00% of C++ online submissions for Interleaving String.
Memory Usage: 6.7 MB, less than 61.72% of C++ online submissions for Interleaving String.

*/