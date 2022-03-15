#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Solution
{
public:
    int maximumTop(vector<int> &nums, int k)
    {

        if (nums.size() == 1)
        {
            return -1;
        }
        if (k == 1)
        {
            return nums[1];
        }
        if (nums.size() == 2)
        {
            if (k % 2 == 1)
            {
                return nums[1];
            }
            else
            {
                return nums[0];
            }
        }
        if (k == 2)
        {
            return max(nums[0], nums[2]);
        }
        int n = nums.size();
        int _max = -1;
        if (k < n)
        {
            int rightIdx = min(n - 1, k);
            _max = nums[rightIdx];
            for (int s = rightIdx - 2; s >= 0; s--)
            {
                _max = max(_max, nums[s]);
            }
        }
        else if (k==n){
            for (int s = 0; s <n-1; s++)
            {
                _max = max(_max, nums[s]);
            }
        }
        else{
            for (int s = 0; s <n; s++)
            {
                _max = max(_max, nums[s]);
            }
        }

        return _max;
    }
};
int main()
{
    /**
     * @brief [35,43,23,86,23,45,84,2,18,83,79,28,54,81,12,94,14,0,0,29,94,12,13,1,48,85,22,95,24,5,73,10,96,97,72,41,52,1,91,3,20,22,41,98,70,20,52,48,91,84,16,30,27,35,69,33,67,18,4,53,86,78,26,83,13,96,29,15,34,80,16,49]
15
     *
[17,61,5,1,44]
100
[2,5,6,2,10,18,14,7,3,0,18,15,10,9,11,19,3,19,4,8,10,14,11,5,2,17,0,2,0,11,12,11,2,9,2,6,0,14,7,19,17,13,4,4,11,19,9,1,10]
6
     */
    vector<int> nums = {2, 5, 6, 2, 10, 18, 14, 7, 3, 0, 18, 15, 10, 9, 11, 19, 3, 19, 4, 8, 10, 14, 11, 5, 2, 17, 0, 2, 0, 11, 12, 11, 2, 9, 2, 6, 0, 14, 7, 19, 17, 13, 4, 4, 11, 19, 9, 1, 10};
    Solution sol;
    int ans = sol.maximumTop(nums, 6);
}