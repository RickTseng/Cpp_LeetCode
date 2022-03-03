#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long start = 0, end = 1e16;

        long long c = 1e16;

        while (start < end)
        {
            long long mid = (start + end) / 2;

            long long trip = 0;
            for (auto &val : time)
            {
                long long b = val;
                trip += (mid / b);
                if (trip > totalTrips)
                    break;
            }
            if (trip >= totalTrips)
            {
                end = mid;
            }
            else
                start = mid + 1;
        }

        return end;
    }
};