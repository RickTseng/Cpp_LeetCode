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
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> sRes;
        vector<int> tmp;
        vector<bool> rc(nums.size(), false);
        build(nums, 0, sRes, tmp, rc);
        vector<vector<int>> res(sRes.begin(), sRes.end()--);
        return res;
    }
    void build(vector<int> nums, int idx, set<vector<int>> &sRes, vector<int> &tmp, vector<bool> &rc)
    {
        if (tmp.size() == nums.size())
        {
            sRes.insert(tmp);
            return;
        }
        for (int jdx = 0;jdx < nums.size(); jdx++)
        {
            if (rc[jdx])
            {
                continue;
            }
            tmp.push_back(nums[jdx]);
            rc[jdx] = true;
            build(nums, jdx, sRes, tmp, rc);
            rc[jdx] = false;
            tmp.pop_back();
        }
    }
};

/***
 * Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3,4,5,6,7,8};
    vector<vector<int>> ans = sol.permuteUnique(nums);
}
