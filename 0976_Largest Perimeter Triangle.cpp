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
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int k = nums.size() - 1;
        while (k - 2 >= 0)
        {
            if(nums[k-2]+nums[k-1]<=nums[k]){
                k--;
            }
            else{
                return nums[k-2]+nums[k-1]+nums[k];
            }
        }
        return 0;
    }
};