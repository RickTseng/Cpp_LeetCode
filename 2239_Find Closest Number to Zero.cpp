#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int _min = 100001;
        int res = nums[0];
        for(auto n:nums)
        {
            if(abs(n)<_min)
            {
                _min = abs(n);
                res = n;
            }
            if(abs(n)==_min)
            {
                _min = abs(n);
                res = max(res,n);
            }
        }
        return res;
    }
};