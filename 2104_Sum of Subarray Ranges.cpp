#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
        long long count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int _max = nums[i];
            int _min = nums[i];
            for (int j = i; j < nums.size(); j++)
            {
                _max = max(_max, nums[j]);
                _min = min(_min, nums[j]);
                dp[0][j] = _max;
                dp[1][j] = _min;
                count += (_max - _min);
            }
        }
        return count;
    }
};
int main()
{
    vector<int> nums = {4, -2, -3, 5, 2, 4, 1,5,9,8,4,1,2,3,5,1,2,4};
    Solution sol;
    cout << sol.subArrayRanges_V1(nums) << endl;
    cout << sol.subArrayRanges(nums) << endl;
}
/*

Runtime: 192 ms, faster than 12.28% of C++ online submissions for Sum of Subarray Ranges.
Memory Usage: 11.1 MB, less than 11.85% of C++ online submissions for Sum of Subarray Ranges.

Constraints:

1 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9


*/