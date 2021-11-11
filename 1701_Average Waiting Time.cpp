#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int _realTime = 0;
        double _allWaitTime = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            if(customers[i][0]>_realTime){
                _realTime = customers[i][0];
            }
            int _cookTime = _realTime + customers[i][1];
            _realTime +=  customers[i][1];
            _allWaitTime += (_realTime - customers[i][0]);
        }
        _allWaitTime /= customers.size();
        return _allWaitTime;
    }
};
int main()
{
    vector<vector<int>> customers = { {1, 2},
                                      {2, 5},
                                      {4, 3}
    };
    Solution sol;
    int ans = sol.averageWaitingTime(customers);
}
/*

Example 1:

Input: customers = [[1,2],[2,5],[4,3]]
Output: 5.00000
Explanation:
1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
So the average waiting time = (2 + 6 + 7) / 3 = 5.

Runtime: 184 ms, faster than 95.05% of C++ online submissions for Average Waiting Time.
Memory Usage: 72.8 MB, less than 89.78% of C++ online submissions for Average Waiting Time.

*/