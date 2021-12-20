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
    long long getDescentPeriods(vector<int> &prices)
    {
        int n = 1;
        long long _sum = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i - 1] - prices[i] == 1)
            {
                n++;
                continue;
            }
            else
            {
                _sum += calculate(n);
                n = 1;
            }
        }
        _sum += calculate(n);
        return _sum;
    }
    int calculate(int n)
    {
        int _sum = 0;
        for (int i = 1; i <= n; i++)
        {
            _sum += i;
        }
        return _sum;
    }
};
int main()
{
    vector<int> prices = {5,3,2,1,7,6};
    Solution sol;
    cout << sol.getDescentPeriods(prices) << endl;
}

/*
1 <= prices.length <= 10^5
1 <= prices[i] <= 10^5

*/