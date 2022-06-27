#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {

        int c1 = INT_MAX, c2 = INT_MAX;
        for (int x : nums)
        {
            if (x <= c1)
            {
                c1 = x; // c1 is min seen so far (it's a candidate for 1st element)
            }
            else if (x <= c2)
            {           // here when x > c1, i.e. x might be either c2 or c3
                c2 = x; // x is better than the current c2, store it
            }
            else
            {                // here when we have/had c1 < c2 already and x > c2
                return true; // the increasing subsequence of 3 elements exists
            }
        }
        return false;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {6, 7, 1, 2};
    bool ans = sol.increasingTriplet(nums);
}
/*
Constraints:

1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1
*/