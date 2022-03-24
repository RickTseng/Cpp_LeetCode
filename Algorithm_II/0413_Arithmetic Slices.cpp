#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);

        for (int i = 1; i < nums.size(); i++)
        {
            vector<int> tmp;
            tmp.push_back(nums[i - 1]);
            worker(nums, nums[i] - nums[i - 1], i, tmp, dp);
        }
        int sum = 0;
        for(auto d:dp){
            sum+=d;
        }
        return sum;
    }
    void worker(vector<int> nums, int target, int &idx, vector<int> tmp, vector<int> &dp)
    {
        if (idx >= nums.size())
        {
            return;
        }
        if (nums[idx - 1] + target == nums[idx])
        {
            tmp.push_back(nums[idx]);
            if (tmp.size() >= 3)
            {
                dp[idx] = dp[idx - 1] + 1;
            }
            worker(nums, target, idx += 1, tmp, dp);
        }
        else
        {
            idx-=1;
            return;
        }
    }
};
int main()
{
    vector<int> nums = {1};
    Solution sol;
    int ans = sol.numberOfArithmeticSlices(nums);
}