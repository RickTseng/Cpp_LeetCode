#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        /*
        vector<int> res(nums.size(), 1);
        
        for (int r = 1; r < nums.size(); r++)
        {
            int index = r;
            for (int i = 0; i < nums.size(); i++)
            {

                if (index >= nums.size())
                {
                    index -= nums.size();
                }
                res[i] *= nums[index];
                index++;
            }
        }

        return res;
        */
       
        int n = nums.size();
        vector<int> ans(n);

        ans[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        int R = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            ans[i] = ans[i] * R;
            R *= nums[i];
        }

        return ans;
        
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    //vector<int> nums(10000, 1);
    vector<int> ans = sol.productExceptSelf(nums);
}
/*
    2 <= nums.length <= 10^5
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.



*/