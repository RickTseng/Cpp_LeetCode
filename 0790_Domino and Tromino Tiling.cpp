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
class Solution
{
public:
    const int MOD = 1000000007;
    int numTilings(int n)
    {
        //dp[5] = dp[4]+dp[3] + (dp[2]+dp[1]+d[0]) * 2
        if (n <= 2)
            return n;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        long long sum = dp[0]; // record the 3-step away cases
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + sum * 2;
            dp[i] = dp[i] % MOD;
            sum += dp[i - 2];
        }
        return dp[n];
    }
};
int main()
{
    Solution sol;
    int ans = sol.numTilings(50);
}
/*
n=3
ans = 5;

50
451995198

1 <= n <= 1000


*/