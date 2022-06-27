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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        for (int i = 0; i < gas.size(); i++)
        {
            int containGas = 0;
            int _nextStop = i;
            int count = 0;
            while (count<gas.size())
            {

                containGas += gas[_nextStop];
                containGas -= cost[_nextStop];
                if (containGas < 0)
                {
                    break;
                }

                _nextStop++;
                if (_nextStop >= gas.size())
                {
                    _nextStop -= gas.size();
                }
                if (_nextStop == i)
                {
                    return i;
                }
                count++;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> gas = {0, 0, 0}, cost = {0, 0, 0};
    Solution sol;
    int ans = sol.canCompleteCircuit(gas, cost);
}
/**
 * @brief 
* 
 */