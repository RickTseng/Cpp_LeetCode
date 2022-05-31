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
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        vector<int> res,dt(1001,0);
        for(auto num:nums)
        {
            for(auto n:num){
                dt[n]++;
            }
        }
        for(int i = 1;i<dt.size();i++){
            if(dt[i]==nums.size()){
                res.push_back(i);
            }
        }
        return res;
    }
};