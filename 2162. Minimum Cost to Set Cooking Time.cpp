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
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds)
    {
        int cost = 0;
        if (targetSeconds < 100)
        {
            cost += min(minCount(startAt, moveCost, pushCost, targetSeconds / 60, targetSeconds%60), secCount(startAt, moveCost, pushCost, targetSeconds));
        }
        else
        {
            int targetMin = targetSeconds/60;
            int _targetSec = targetSeconds%60;
            cost += min(minCount(startAt, moveCost, pushCost, targetSeconds / 60, _targetSec),minCount(startAt, moveCost, pushCost, targetSeconds / 60 - 1, _targetSec+60));
        }
        return cost;
    }
    int minCount(int startAt, int moveCost, int pushCost, int targetMin, int targetSeconds)
    {
        int cost = 0;
        //int targetMin = targetSeconds / 60;
        //targetSeconds %= 60;
        if(targetMin<0 || targetSeconds>99){
            return INT_MAX;
        }
        if (targetMin > 99)
        {
            targetMin = 99;
            targetSeconds += 60;
        }
        if (targetMin >= 10)
        {
            if (startAt != targetMin / 10)
            {
                cost += moveCost;
                startAt = targetMin / 10;
            }
            cost += pushCost;
            targetMin %= 10;
        }
        if (startAt != targetMin)
        {
            cost += moveCost;
            startAt = targetMin;
        }
        cost += pushCost;
        if (targetSeconds >= 10)
        {
            if (startAt != targetSeconds / 10)
            {
                cost += moveCost;
                startAt = targetSeconds / 10;
            }
            cost += pushCost;
            targetSeconds %= 10;
        }
        else
        {
            if (startAt != 0)
            {
                cost += moveCost;
                startAt = 0;
            }
            cost += pushCost;
        }
        if (startAt != targetSeconds)
        {
            cost += moveCost;
            startAt = targetSeconds;
        }
        cost += pushCost;
        return cost;
    }
    int secCount(int startAt, int moveCost, int pushCost, int targetSeconds)
    {
        int cost = 0;
        if (targetSeconds >= 10)
        {
            if (startAt != targetSeconds / 10)
            {
                cost += moveCost;
                startAt = targetSeconds / 10;
            }
            cost += pushCost;
            targetSeconds %= 10;
        }
        if (startAt != targetSeconds)
        {
            cost += moveCost;
            startAt = targetSeconds;
        }
        cost += pushCost;
        return cost;
    }
};
int main()
{
    Solution sol;
    int ans = sol.minCostSetTime(1,1219,1218,73);
}