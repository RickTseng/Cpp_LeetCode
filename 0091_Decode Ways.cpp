#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, 0);
        if (s[0] == '0')
        {
            return 0;
        }
        dp[0] = 1;
        dp[1] = 1;
        int tmp = 1;
        for (int i = 2; i < dp.size(); i++)
        {
            int x1 = s[i - 1] - '0';
            int x2 = (s[i - 2] - '0') * 10 + x1;
            if(x2==0){
                return 0;
            }
            if (x1 > 0 && x2 < 27 && s[i - 2] != '0')
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else
            {
                if (x2 > 26)
                {
                    if(x2%10==0){
                        return 0;
                    }
                    dp[i] = dp[i - 1];
                }
                else
                {
                    dp[i] = min(dp[i - 1], dp[i - 2]);
                }
                
            }
        }
        return dp[dp.size() - 1];
    }
};
int main()
{
    Solution sol;
    int ans = sol.numDecodings("10011");
}
/*
input: s="11106"
output: 2 = 1 1 10 6, 11 10 6

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).

Runtime: 4 ms, faster than 31.21% of C++ online submissions for Decode Ways.
Memory Usage: 6.2 MB, less than 42.22% of C++ online submissions for Decode Ways.

*/