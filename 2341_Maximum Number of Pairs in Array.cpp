#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;

// Runtime: 2 ms, faster than 50.00% of C++ online submissions for Maximum Number of Pairs in Array.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Maximum Number of Pairs in Array.

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) 
    {
        int count = 0,idx = 0;
        sort(begin(nums),end(nums));
        while (idx<nums.size())
        {
            if(idx+1<nums.size())
            {
                if(nums[idx]==nums[idx+1])
                {
                    nums.erase(begin(nums)+idx);
                    nums.erase(begin(nums)+idx);
                    count++;
                    continue;
                }
            }
            idx++;
            
        }
        return {count,(int)nums.size()};
    }
};
int main(){
    vector<int> nums = {1,1,1,1,2,3,3,4};
    Solution sol;
    auto ans = sol.numberOfPairs(nums);
}