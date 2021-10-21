#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {

        vector<int> res(1, 0);
        if (n == 0)
        {
            return res;
        }
        for (int i = 1; i <= 17; i++)
        {
            vector<int> tmp = res;
            for (auto t : tmp)
            {
                res.push_back(t + 1);
                if (res.size() == n + 1)
                {
                    break;
                }
            }
            if (res.size() == n + 1)
            {
                break;
            }
        }
        //vector<int> ans;
        //ans.insert(ans.begin(),res.begin(),res.begin()+n+1);
        return res;
    }

    int hammingWeight(uint32_t n)
    {
        uint32_t p = 1;
        int count = 0;
        while (p <= n && p != 0)
        {
            int c = n & p;
            if (n & p)
            {
                count++;
            }
            p *= 2;
        }

        return count;
    }
    int fib(int n)
    {
        //0<=n<=30
        vector<int> fb(2, 0);
        fb[1] = 1;
        if (n < 2)
        {
            return fb[n];
        }
        for (int i = 2; i <= n; i++)
        {
            fb.push_back(fb[i - 1] + fb[i - 2]);
        }
        return fb[n];
    }
    bool divisorGame(int n)
    {
        vector<bool> dp;
        dp.push_back(false); //0
        dp.push_back(false); //1
        dp.push_back(true);  //2

        for (int t = 3; t <= n; t++)
        {
            int count = t;
            bool aGet = false;
            bool bGet = false;
            while (count > 0)
            {       
                aGet = false;
                bGet = false;  
                for (int i = 1; i < count; i++)
                {
                    if (count % i == 0 && !dp[count - i])
                    {
                        count -= i;
                        aGet = true;
                        break;
                    }
                }
                if (!aGet)
                {
                    count -= 1;
                }
                for (int i = 1; i < count; i++)
                {
                    if (count % i == 0 && !dp[count - i])
                    {
                        count -= i;
                        bGet = true;
                        break;
                    }
                }
                if (!bGet)
                {
                    count -= 1;
                }
            }
            dp.push_back(aGet);
        }
        return dp[n];
    }
};
int main()
{
    Solution sol;
    //vector<int> ans = sol.countBits(0);
    //int ans = sol.hammingWeight(11);
    bool ans = sol.divisorGame(1000);
}

/*

    Example 1:

    Input: n = 2
    Output: [0,1,1]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10
    
    Example 2:

    Input: n = 5
    Output: [0,1,1,2,1,2]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10
    3 --> 11
    4 --> 100
    5 --> 101
    
    Constraints:

    0 <= n <= 10^5
 

    Follow up:

    It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
    Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?


    Example 1:

    Input: n = 2
    Output: 1
    Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

    Example 2:

    Input: n = 3
    Output: 2
    Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

    Example 3:

    Input: n = 4
    Output: 3
    Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.


*/