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

// Runtime: 179 ms, faster than 100.00% of C++ online submissions for Max Sum of a Pair With Equal Sum of Digits.
// Memory Usage: 60.3 MB, less than 100.00% of C++ online submissions for Max Sum of a Pair With Equal Sum of Digits.

class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        vector<vector<int>> tb(100,vector<int>(2,0));
        int _max = -1;
        for(auto n:nums)
        {
            if(n>tb[calSum(n)][0])
            {
                tb[calSum(n)][1] = tb[calSum(n)][0];
                tb[calSum(n)][0] = n;
                if(tb[calSum(n)][0]!=0 && tb[calSum(n)][1]!=0)
                {
                    _max = max(_max,tb[calSum(n)][0]+ tb[calSum(n)][1]);
                }
                
                continue;
            }
            if(n>tb[calSum(n)][1])
            {
                tb[calSum(n)][1] = n;
                if(tb[calSum(n)][0]!=0 && tb[calSum(n)][1]!=0)
                {
                    _max = max(_max,tb[calSum(n)][0]+ tb[calSum(n)][1]);
                }
                continue;
            }
            
        }
        return _max;

    }
    int calSum(int source)
    {
        int res = 0;
        while(source>0)
        {
            res+=(source%10);
            source/=10;
        }
        return res;
    }
};
int main(){
    vector<int> nums = {9,18,43,72,36,13,7,54};
    Solution sol;
    auto ans = sol.maximumSum(nums);
}