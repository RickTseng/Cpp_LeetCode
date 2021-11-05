#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            
            int target = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > target)
                {
                    dp[i]++;
                    //target = nums[j];
                }
            }
        }
        
        int _val = -10001;
        int _index = -1;
        int startIndex = 0;
        int count = 0;
        int _number = -10001;
        vector<int> tmp;
        while (startIndex<dp.size())
        {
            int _max = -1;         
            bool get = false;
            for (int i = startIndex; i < dp.size(); i++)
            {
                if (dp[i] > _max && nums[i] > _number)
                {
                    _max = dp[i];
                    _val = nums[i];
                    _index = i;
                    get = true;
                }
                if (dp[i] == _max && nums[i] > _number && nums[i]<_val)
                {
                    _max = dp[i];
                    _val = nums[i];
                    _index = i;
                    get = true;
                }
            }
            if(get){
                count++;
                tmp.push_back(_val);
                _number = _val;
                startIndex = _index;
            }
            startIndex++;
        }
        
        return count;
    }
};
class Solution_web{
    public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (auto a : nums)
        {
            if (find(v.begin(), v.end(), a) != v.end())
            {
                continue;
            }
            auto it = upper_bound(v.begin(), v.end(), a);
            if (it == v.end())
            {
                v.push_back(a);
            }
            else
            {
                *it = a;
            }
        }
        return v.size();
    }
};
int main()
{
    Solution_web sol;
    vector<int>nums1 = {10,9,2,5,3,7,101,18};
    vector<int>nums2 = {0,1,0,3,2,3};
    vector<int>nums3 = {7,7,7,7,7,7,7};
    vector<int>nums4 = {2,15,3,7,8,6,18};//5
    vector<int>nums5 = {1,2,3,4,5,8,6,4,1,1,1,0,2,1,2,3,1,5,7,8,9,6,1,0,44,5,6,6,6,1,2,3,1,0,0,0,1,2,3,4,5,6,7,8,9,1,0};//10
    vector<int>nums6 = {3,5,6,2,5,4,19,5,6,7,12};//6
    int ans = sol.lengthOfLIS(nums6);
}
/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/