#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int _max = 0,idx = 0;
        while (idx < nums.size())
        {
            int count = 0;
            while (idx < nums.size() && nums[idx]== 1)
            {
                count++;
                idx++;
            }
            _max = max(_max,count);
            idx++;
        }
        return _max;
        
    }
};