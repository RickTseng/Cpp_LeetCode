#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        map<int, int> db;
        int _time = 1;
        int _total = 0;
        while (_total < tickets.size())
        {
            _total = 0;
            for (int i = 0; i < tickets.size(); i++)
            {
                if (tickets[i] != 0)
                {
                    tickets[i]--;
                    db[i] = _time;
                    _time++;
                }
                else
                {
                    _total++;
                }
            }
        }

        return db[k];
    }
};
int main()
{
    Solution sol;
    vector<int> t = {5, 1, 1, 1};
    int ans = sol.timeRequiredToBuy(t, 0);
}
/*
Runtime: 12 ms, faster than 27.27% of C++ online submissions for Time Needed to Buy Tickets.
Memory Usage: 8 MB, less than 50.00% of C++ online submissions for Time Needed to Buy Tickets.

*/