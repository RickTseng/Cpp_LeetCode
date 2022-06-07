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
class Solution {
public:
    int minMaxGame(vector<int>& nums) 
    {
        
        while (nums.size()>1)
        {
            vector<int> tmp;
            bool _min = true;
            for(int i = 1;i<nums.size();i+=2){
                if(_min){
                    tmp.push_back(min(nums[i],nums[i-1]));
                    _min = false;
                }
                else
                {
                    tmp.push_back(max(nums[i],nums[i-1]));
                    _min = true;
                }
            }
            nums = tmp;
        }
        return nums[0];
    }
};
int main(){
    vector<int> nums = {1,3,5,2,4,8,2,2};
    Solution sol;
    int ans = sol.minMaxGame(nums);
}