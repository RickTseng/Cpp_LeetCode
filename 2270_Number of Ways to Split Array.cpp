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
    int waysToSplitArray(vector<int>& nums) {
        long long r_sum = 0,l_sum = 0;
        int res = 0;
        for(auto n:nums){
            r_sum+=n;
        }
        for(int i = 0;i + 1<nums.size();i++)
        {
            if(i == nums.size()-1) break;
            l_sum+=nums[i];
            r_sum-=nums[i];
            if(l_sum>=r_sum){
                res++;
            }
        }
        return res;
    }
};