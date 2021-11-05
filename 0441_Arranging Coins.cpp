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
    int arrangeCoins(int n)
    {
        long long b = 1;
        int count = 0;
        while (n>=0)
        {
            n -=b;
            if(n>=0){
                count++;
            }
            b++;
        }
        return count;

    }
};
int main()
{
    Solution sol;
    int ans = sol.arrangeCoins(2147000000);

}
/*

1 <= n <= 2^31 - 1

*/