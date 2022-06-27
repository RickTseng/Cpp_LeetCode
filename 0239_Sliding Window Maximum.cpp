#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); i++)
        {
            if (dq.front() <= i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = sol.maxSlidingWindow(nums, 3);
}
/*

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
*/