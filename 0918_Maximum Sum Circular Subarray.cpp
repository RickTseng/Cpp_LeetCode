#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int Min = INT_MAX;
        int Max1 = INT_MIN;
        int Max2 = INT_MIN;
        int sum = 0;
        int total_sum = 0;
        for(auto n:nums){
            total_sum+=n;
        }
		//Kadane's algo to find the Minimum
        for(int a : nums)
        {
            sum += a;
            if(sum < Min)
                Min = sum;
            if(sum > 0)
                sum = 0;
        }
        sum = 0;
		//Kadane's algo to find the Maximum
        for(int a : nums)
        {
            sum += a;
            if(sum > Max1)
                Max1 = sum;
            if(sum < 0)
                sum = 0;
        }
        Max2 = (( total_sum - Min) == 0) ? INT_MIN : (total_sum - Min);
        return max(Max1,Max2);
    }
};
int main()
{
    vector<int> nums = {5, -3, 5};
    Solution sol;
    int ans = sol.maxSubarraySumCircular(nums);
}