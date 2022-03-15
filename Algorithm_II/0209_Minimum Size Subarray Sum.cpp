#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, _min = 100001;
        for (int right = 0; right < nums.size(); right++)
        {
            target -= nums[right];
            if (target <= 0)
            {
                _min = min(_min, right - left + 1);
            }
            while (left <= right && target + nums[left]<= 0)
            {
                target += nums[left];
                left++;
            }
            if (target <= 0)
            {
                _min = min(_min, right - left + 1);
            }
        }
        if (target > 0)
        {
            return 0;
        }
        return _min;
    }
};
int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    Solution sol;
    int ans = sol.minSubArrayLen(7, nums);
}