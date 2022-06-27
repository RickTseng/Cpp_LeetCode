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

//PASS
class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int right = 0,left = 0;
        for(auto n:nums){
            right+=n;
        }
        for(int i = 0;i<nums.size();++i){
            right-=nums[i];
            if(left==right){
                return i;
            }
            left+=nums[i];
        }
        return -1;
    }
};