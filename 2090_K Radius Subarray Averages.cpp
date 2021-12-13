#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return nums;
        }
        int avg = k * 2 + 1;
        long long tmpSum = 0;
        vector<int> res(nums.size(), -1);
        if (k > nums.size() || nums.size() < avg)
        {
            return res;
        }
        for(int i = 0;i<avg;i++){
            tmpSum+=nums[i];
        }
        res[k] = tmpSum / avg;
        for (int i = avg; i < nums.size(); i++)
        {
            tmpSum+=nums[i];
            tmpSum-=nums[i-avg];
            res[i - k] = tmpSum / avg;
        }
        return res;
    }
};
int main(){
    Solution sol;
    std::vector<int> nums = {7,4,3,9,1,8,5,2,6};
    vector<int> nums2(100000,100000);
    vector<int> ans = sol.getAverages(nums2,49999);
}
/*

Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]

Constraints:

n == nums.length
1 <= n <= 10^5
0 <= nums[i], k <= 10^5


*/