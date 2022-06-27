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
    bool isMonotonic(vector<int>& nums) {
        int idx = 0,jdx = 1;
        while (jdx<nums.size() && nums[jdx] == nums[idx])
        {
            jdx++;
            idx++;
        }
        if(jdx>=nums.size()){
            return true;
        }
        if(nums[jdx]>nums[idx])
        {
            return incre(nums,jdx);
        }
        if(nums[jdx]<nums[idx])
        {
            return decre(nums,jdx);
        }
        return true;
    }
    bool incre(vector<int> nums,int jdx)
    {
        for(;jdx<nums.size();jdx++){
            if(nums[jdx]<nums[jdx-1]){
                return false;
            }
        }
        return true;
    }
    bool decre(vector<int> nums,int jdx)
    {

        for(;jdx<nums.size();jdx++){
            if(nums[jdx]>nums[jdx-1]){
                return false;
            }
        }
        return true;
        
    }
};
int main(){
    vector<int> nums ={1,2};
    Solution sol;
    bool ans = sol.isMonotonic(nums);
}