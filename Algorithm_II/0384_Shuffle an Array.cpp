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
    vector<int> org;
    vector<int> _nums;
    Solution(vector<int> &nums)
    {
        org = nums;
        _nums = nums;
        
    }

    vector<int> reset()
    {
        return org;
    }

    vector<int> shuffle()
    {
        if(_nums.size()==1)return _nums;
        for(int i=0;i<_nums.size();i++)
        {
            swap(_nums[i],_nums[rand()%_nums.size()]);
        }
        return _nums;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    Solution sol = Solution(nums);
    vector<int> ans = sol.shuffle();
}
