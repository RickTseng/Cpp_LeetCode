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
    int minStartValue(vector<int> &nums)
    {
        
        int startValue = 1;
        while (true)
        {
            int sum = startValue;
            int count = 0;
            for (auto n : nums)
            {
                sum += n;
                if (sum < 1)
                {
                    break;
                }
                count++;
            }
            if(count == nums.size()){
                break;
            }
            startValue++;
        }
        return startValue;
    }
};
int main()
{
    vector<int> nums = {1,-2,-3};
    Solution sol;
    int ans = sol.minStartValue(nums);
}
/*
Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
                step by step sum
                startValue = 4 | startValue = 5 | nums
                  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
                  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
                  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
                  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
                  (4 +2 ) = 6  | (5 +2 ) = 7    |   2
Example 2:

Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive. 
Example 3:

Input: nums = [1,-2,-3]
Output: 5
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100

Runtime: 4 ms, faster than 27.86% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
Memory Usage: 7.4 MB, less than 14.12% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.


*/